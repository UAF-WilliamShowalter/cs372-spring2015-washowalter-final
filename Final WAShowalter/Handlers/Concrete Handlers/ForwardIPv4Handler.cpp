//
//  ForwardIPv4Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "ForwardIPv4Handler.h"
#include "NullHandler.h"
#include <memory>

void ForwardIPv4Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv6" && r->getDirection() == FORWARD){
		_logObserver->notify("Request fell of end of chain: ");
	}
	else {
		std::unique_ptr<Handler> nullHandler = std::make_unique<NullHandler>();
		nullHandler->registerLogObserver(_logObserver);
		nullHandler->handleRequest(std::move(r));
	}
}

void ForwardIPv4Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
