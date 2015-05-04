//
//  Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "Handler.h"

void Handler::registerLogObserver(std::shared_ptr<HandlerObserver> observer) {
	_logObserver = observer;
}

void Handler::setSuccessor(std::unique_ptr<Handler> r) {
	_successor = move(r);
}