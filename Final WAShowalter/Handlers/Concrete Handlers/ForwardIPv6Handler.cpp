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
		_successor->registerLogObserver(_logObserver);
		_successor->handleRequest(std::move(r));
	}
}