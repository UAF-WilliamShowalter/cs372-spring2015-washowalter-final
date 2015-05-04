//
//  InputIPv6Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "InputIPv6Handler.h"
#include "OutputIPv4Handler.h"
#include <memory>

void InputIPv6Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv6" && r->getDirection() == INPUT){
		_logObserver->notify("Handled by InputIPv6Handler");
	}
	else {
		std::unique_ptr<Handler> nextHandler = std::make_unique<OutputIPv4Handler>();
		nextHandler->registerLogObserver(_logObserver);
		nextHandler->handleRequest(std::move(r));
	}
}

void InputIPv6Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
