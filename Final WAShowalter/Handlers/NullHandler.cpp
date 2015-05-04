//
//  NullHandler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "NullHandler.h"

void NullHandler::handleRequest(std::unique_ptr<Request> r) {
	_logObserver->notify("Request fell of end of chain: ");
}
void NullHandler::setSuccessor(std::unique_ptr<Handler> successor) {
	// Null Handler does not need to maintain a successor, as it ends the chain.
}

void NullHandler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}
