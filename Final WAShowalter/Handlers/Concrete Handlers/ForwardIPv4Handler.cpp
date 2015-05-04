//
//  ForwardIPv4Handler.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "ForwardIPv4Handler.h"
#include "ForwardIPv6Handler.h"
#include <memory>

void ForwardIPv4Handler::handleRequest(std::unique_ptr<Request> r) {
	if (r->getType() == "IPv4" && r->getDirection() == FORWARD){
		_logObserver->notify("Handled by ForwardIPv4Handler");
	}
	else {
		_successor->registerLogObserver(_logObserver);
		_successor->handleRequest(std::move(r));
	}
}