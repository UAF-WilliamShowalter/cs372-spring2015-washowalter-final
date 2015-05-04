//
//  CatchMain.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include <stdio.h>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdio>
using std::remove;

#include <memory>
using std::make_shared;
using std::make_unique;
using std::unique_ptr;
using std::shared_ptr;
using std::move;

#include "HandlerObserver.h"
#include "Request.h"
#include "IPv4Request.h"
#include "IPv6Request.h"
#include "Handler.h"
#include "NullHandler.h"
#include "InputIPv4Handler.h"
#include "InputIPv6Handler.h"
#include "OutputIPv4Handler.h"
#include "OutputIPv6Handler.h"
#include "ForwardIPv4Handler.h"
#include "ForwardIPv6Handler.h"
#include "UnsupportedProtocolRequest.h"


TEST_CASE("Chain of Responsibility Firewall", "Final")
{
	// TEST 1 -- NULLHANDLER //
	// Tests the simple case of the fall through handler logging the appropriate value

	shared_ptr<HandlerObserver> logReporter1 = make_shared<HandlerObserver>();
	unique_ptr<NullHandler> null1 = make_unique<NullHandler>();

	null1->registerLogObserver(logReporter1);
	null1->handleRequest(make_unique<IPv4Request>(INPUT, "192.168.1.1", "192.168.2.1", "DATA MESSAGE"));

	REQUIRE(logReporter1->getLogs() == "Request fell of end of chain: \n");



	// TEST 2 -- ForwardIPv6Handler handles 1st, NullHandler handles 2nd //
	// Tests the case of the last handler passing unhandled request to null handler

	shared_ptr<HandlerObserver> logReporter2 = make_shared<HandlerObserver>();
	unique_ptr<Handler> ForwardIPv6_1 = make_unique<ForwardIPv6Handler>();

	ForwardIPv6_1->registerLogObserver(logReporter2);
	ForwardIPv6_1->setSuccessor(move(null1));
	ForwardIPv6_1->handleRequest(make_unique<IPv6Request>(FORWARD, "FE80::0", "FE81::0", "DATA MESSAGE"));

	REQUIRE(logReporter2->getLogs() == "Handled by ForwardIPv6Handler\n");

	ForwardIPv6_1->handleRequest(make_unique<IPv6Request>(INPUT, "FE80::0", "FE81::0", "DATA MESSAGE"));
	REQUIRE(logReporter2->getLogs() == "Handled by ForwardIPv6Handler\nRequest fell of end of chain: \n");



	// TEST 3 -- One of each, in order
	// Tests 7 requests, one for each handler, in order.
	// All tests go through the entire chain, starting with InputIPv4Handler

	shared_ptr<HandlerObserver> logReporter3 = make_shared<HandlerObserver>();

	// Make handlers
	unique_ptr<Handler> handler = make_unique<InputIPv4Handler>();
	unique_ptr<Handler> handler2 = make_unique<InputIPv6Handler>();
	unique_ptr<Handler> handler3 = make_unique<OutputIPv4Handler>();
	unique_ptr<Handler> handler4 = make_unique<OutputIPv6Handler>();
	unique_ptr<Handler> handler5 = make_unique<ForwardIPv4Handler>();
	unique_ptr<Handler> handler6 = make_unique<ForwardIPv6Handler>();
	unique_ptr<Handler> handler7 = make_unique<NullHandler>();

	handler->registerLogObserver(logReporter3);

	// Setup chain of handlers -- has to go in reverse order because of unique_ptr ownership
	handler6->setSuccessor(move(handler7));
	handler5->setSuccessor(move(handler6));
	handler4->setSuccessor(move(handler5));
	handler3->setSuccessor(move(handler4));
	handler2->setSuccessor(move(handler3));
	handler->setSuccessor(move(handler2));

	// Setup requests
	unique_ptr<Request> ipv4Input = make_unique<IPv4Request>(INPUT, "192.168.1.1", "192.168.2.1", "DATA MESSAGE");
	unique_ptr<Request> ipv6Input = make_unique<IPv6Request>(INPUT, "FE80::0", "FE81::0", "DATA MESSAGE");
	unique_ptr<Request> ipv4Output = make_unique<IPv4Request>(OUTPUT, "192.168.1.1", "192.168.2.1", "DATA MESSAGE");
	unique_ptr<Request> ipv6Output = make_unique<IPv6Request>(OUTPUT, "FE80::0", "FE81::0", "DATA MESSAGE");
	unique_ptr<Request> ipv4Forward = make_unique<IPv4Request>(FORWARD, "192.168.1.1", "192.168.2.1", "DATA MESSAGE");
	unique_ptr<Request> ipv6Forward = make_unique<IPv6Request>(FORWARD, "FE80::0", "FE81::0", "DATA MESSAGE");
	unique_ptr<Request> unsupported = make_unique<UnsupportedProtocolRequest>(INPUT, "**/n1`/**", "**/n2`/**", "DATA MESSAGE");

	// Execute requests
	handler->handleRequest(move(ipv4Input));
	handler->handleRequest(move(ipv6Input));
	handler->handleRequest(move(ipv4Output));
	handler->handleRequest(move(ipv6Output));
	handler->handleRequest(move(ipv4Forward));
	handler->handleRequest(move(ipv6Forward));
	handler->handleRequest(move(unsupported));

	// Check results
	string ipv4InputString = "Handled by InputIPv4Handler\n";
	string ipv6InputString = "Handled by InputIPv6Handler\n";
	string ipv4OutputString = "Handled by OutputIPv4Handler\n";
	string ipv6OutputString = "Handled by OutputIPv6Handler\n";
	string ipv4ForwardString = "Handled by ForwardIPv4Handler\n";
	string ipv6ForwardString = "Handled by ForwardIPv6Handler\n";
	string unsupportedString = "Request fell of end of chain: \n";

	REQUIRE(logReporter3->getLogs() == ipv4InputString + ipv6InputString
									 + ipv4OutputString + ipv6OutputString
									 + ipv4ForwardString + ipv6ForwardString
									 + unsupportedString);
}
