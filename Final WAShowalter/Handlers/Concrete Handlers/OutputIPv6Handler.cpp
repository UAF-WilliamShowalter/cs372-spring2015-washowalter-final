//
//  OutputIPv6Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "OutputIPv6Handler.h"
#include "ForwardIPv4Handler.h"
#include <memory>

void OutputIPv6Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv6" && r->getDirection() == OUTPUT){
		_logObserver->notify("Handled by OutputIPv6Handler");
	}
	else {
		std::unique_ptr<Handler> nextHandler = std::make_unique<ForwardIPv4Handler>();
		nextHandler->registerLogObserver(_logObserver);
		nextHandler->handleRequest(std::move(r));
	}
}

void OutputIPv6Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
