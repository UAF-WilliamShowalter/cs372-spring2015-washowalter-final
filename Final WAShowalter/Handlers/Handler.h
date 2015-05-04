//
//  Handler.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__Handler__
#define __Final_WAShowalter__Handler__

#include <stdio.h>
#include <memory>
#include "Request.h"
#include "HandlerObserver.h"

class Handler {
public:
	virtual ~Handler() = default;

	virtual void handleRequest(std::unique_ptr<Request> r) = 0;
	virtual void setSuccessor(std::unique_ptr<Handler> r);
	
	// HandlerObserver Records the logs of the firewall
	// It's away of avoiding writing my already contrived handlers with cout statements in the class.
	// And allows for an easier mechanism for testing and acts like a syslog service.
	virtual void registerLogObserver(std::shared_ptr<HandlerObserver>);

protected:
	std::unique_ptr<Handler> _successor;
	std::shared_ptr<HandlerObserver> _logObserver;
};

#endif /* defined(__Final_WAShowalter__Handler__) */
