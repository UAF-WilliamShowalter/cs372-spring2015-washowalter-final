//
//  InputIPv6Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "InputIPv6Handler.h"
#include "NullHandler.h"
#include <memory>

void InputIPv6Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv6" && r->getDirection() == FORWARD){
		_logObserver->notify("Request fell of end of chain: ");
	}
	else {
		std::unique_ptr<Handler> nullHandler = std::make_unique<NullHandler>();
		nullHandler->registerLogObserver(_logObserver);
		nullHandler->handleRequest(std::move(r));
	}
}

void InputIPv6Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
