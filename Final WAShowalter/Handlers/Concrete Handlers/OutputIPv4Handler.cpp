//
//  OutputIPv4Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "OutputIPv4Handler.h"
#include "OutputIPv6Handler.h"
#include <memory>

void OutputIPv4Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv4" && r->getDirection() == OUTPUT){
		_logObserver->notify("Handled by OutputIPv4Handler");
	}
	else {
		std::unique_ptr<Handler> nextHandler = std::make_unique<OutputIPv6Handler>();
		nextHandler->registerLogObserver(_logObserver);
		nextHandler->handleRequest(std::move(r));
	}
}

void OutputIPv4Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
