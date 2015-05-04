//
//  ForwardIPv6Handler.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__ForwardIPv6Handler__
#define __Final_WAShowalter__ForwardIPv6Handler__

#include <stdio.h>
#include "Handler.h"

class ForwardIPv6Handler : public Handler {
public:
	void handleRequest(std::unique_ptr<Request> r);
	void registerLogObserver(std::shared_ptr<HandlerObserver>);
	void setSuccessor(std::unique_ptr<Handler> r);

private:
	std::shared_ptr<HandlerObserver> _logObserver;
	std::shared_ptr<Handler> _successor;
};

#endif /* defined(__Final_WAShowalter__ForwardIPv6Handler__) */
