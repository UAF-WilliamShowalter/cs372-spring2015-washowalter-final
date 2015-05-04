//
//  ForwardIPv6Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "ForwardIPv6Handler.h"
#include "NullHandler.h"
#include <memory>

void ForwardIPv6Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv6" && r->getDirection() == FORWARD){
		_logObserver->notify("Handled by ForwardIPv6Handler");
	}
	else {
		std::unique_ptr<Handler> nextHandler = std::make_unique<NullHandler>();
		nextHandler->registerLogObserver(_logObserver);
		nextHandler->handleRequest(std::move(r));
	}
}

void ForwardIPv6Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
