//
//  main.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

// Chain of Responsibility Pattern
// Chain goes as follows:
/*
	InputIPv4Handler -> InputIPv6Handler -> OutputIPv4Handler -> OutputIPv6Handler ->
 ForwardIPv4Handler ->  ForwardIPv6Handler -> NullHandler

	NullHandler is an implementation of the Null Object design pattern.
 */

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

int main(int argc, const char * argv[]) {


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

	// Execute example requests
	handler->handleRequest(move(ipv4Input));
	handler->handleRequest(move(ipv6Input));
	handler->handleRequest(move(ipv4Output));
	handler->handleRequest(move(ipv6Output));
	handler->handleRequest(move(ipv4Forward));
	handler->handleRequest(move(ipv6Forward));
	handler->handleRequest(move(unsupported));

	std::cout << "Ordered examples:\n" << logReporter3->getLogs();

	logReporter3->clearLogs();

	// Setup new requests -- unique pointers

	// Setup requests
	ipv4Input = make_unique<IPv4Request>(INPUT, "192.168.1.1", "192.168.2.1", "DATA MESSAGE");
	ipv6Input = make_unique<IPv6Request>(INPUT, "FE80::0", "FE81::0", "DATA MESSAGE");
	ipv4Output = make_unique<IPv4Request>(OUTPUT, "192.168.1.1", "192.168.2.1", "DATA MESSAGE");
	ipv6Output = make_unique<IPv6Request>(OUTPUT, "FE80::0", "FE81::0", "DATA MESSAGE");
	ipv4Forward = make_unique<IPv4Request>(FORWARD, "192.168.1.1", "192.168.2.1", "DATA MESSAGE");
	ipv6Forward = make_unique<IPv6Request>(FORWARD, "FE80::0", "FE81::0", "DATA MESSAGE");
	unsupported = make_unique<UnsupportedProtocolRequest>(INPUT, "**/n1`/**", "**/n2`/**", "DATA MESSAGE");

	// Execute example requests
	handler->handleRequest(move(unsupported));
	handler->handleRequest(move(ipv4Forward));
	handler->handleRequest(move(ipv4Input));
	handler->handleRequest(move(ipv6Output));

	std::cout << "\n\nUnordered examples:\n" << logReporter3->getLogs();

    return 0;
}
