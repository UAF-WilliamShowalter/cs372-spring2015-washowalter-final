//
//  InputIPv6Handler.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__InputIPv6Handler__
#define __Final_WAShowalter__InputIPv6Handler__

#include <stdio.h>
#include "Handler.h"

class InputIPv6Handler : public Handler {
public:
	void handleRequest(std::unique_ptr<Request> r);
	void registerLogObserver(std::shared_ptr<HandlerObserver>);

private:
	std::shared_ptr<HandlerObserver> _logObserver;
};
#endif /* defined(__Final_WAShowalter__InputIPv6Handler__) */
