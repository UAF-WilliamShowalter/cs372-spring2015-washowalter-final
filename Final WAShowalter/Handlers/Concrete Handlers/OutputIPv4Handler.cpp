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
		_successor->registerLogObserver(_logObserver);
		_successor->handleRequest(std::move(r));
	}
}

void OutputIPv4Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}

void OutputIPv4Handler::setSuccessor(std::unique_ptr<Handler> r) {
	_successor = move(r);
}