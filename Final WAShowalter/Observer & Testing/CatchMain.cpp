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


TEST_CASE("Chain of Responsibility Firewall", "Final")
{
	// TEST 1 -- NULLHANDLER //

	shared_ptr<HandlerObserver> logReporter1 = make_shared<HandlerObserver>();
	unique_ptr<NullHandler> null1 = make_unique<NullHandler>();

	null1->registerLogObserver(logReporter1);
	null1->handleRequest(make_unique<IPv4Request>(INPUT, "192.168.1.1", "192.168.2.1", "DATA MESSAGE"));

	REQUIRE(logReporter1->getLogs() == "Request fell of end of chain: \n");



	// TEST 2 -- ForwardIPv6Handler handles 1st, NullHandler handles 2nd //

	shared_ptr<HandlerObserver> logReporter2 = make_shared<HandlerObserver>();
	unique_ptr<Handler> ForwardIPv6_1 = make_unique<ForwardIPv6Handler>();

	ForwardIPv6_1->registerLogObserver(logReporter2);
	ForwardIPv6_1->handleRequest(make_unique<IPv6Request>(FORWARD, "FE80::0", "FE81::0", "DATA MESSAGE"));

	REQUIRE(logReporter2->getLogs() == "Handled by ForwardIPv6Handler\n");

	ForwardIPv6_1->handleRequest(make_unique<IPv4Request>(INPUT, "FE80::0", "FE81::0", "DATA MESSAGE"));
	REQUIRE(logReporter2->getLogs() == "Handled by ForwardIPv6Handler\nRequest fell of end of chain: \n");
}
