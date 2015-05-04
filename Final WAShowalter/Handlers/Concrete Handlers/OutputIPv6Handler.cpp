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
		_successor->registerLogObserver(_logObserver);
		_successor->handleRequest(std::move(r));
	}
}

void OutputIPv6Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}

void OutputIPv6Handler::setSuccessor(std::unique_ptr<Handler> r) {
	_successor = move(r);
}
