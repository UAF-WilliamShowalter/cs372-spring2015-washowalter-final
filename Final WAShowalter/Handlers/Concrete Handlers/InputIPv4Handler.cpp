//
//  InputIPv4Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "InputIPv4Handler.h"
#include "InputIPv6Handler.h"
#include <memory>

void InputIPv4Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv4" && r->getDirection() == INPUT){
		_logObserver->notify("Handled by InputIPv4Handler");
	}
	else {
		_successor->registerLogObserver(_logObserver);
		_successor->handleRequest(std::move(r));
	}
}

void InputIPv4Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}

void InputIPv4Handler::setSuccessor(std::unique_ptr<Handler> r) {
	_successor = move(r);
}