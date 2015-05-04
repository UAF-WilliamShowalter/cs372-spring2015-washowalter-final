//
//  UnsupportedProtocolRequest.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__UnsupportedProtocolRequest__
#define __Final_WAShowalter__UnsupportedProtocolRequest__

#include <stdio.h>
#include "Request.h"

class UnsupportedProtocolRequest : public Request {
/*
 A protocol none of the firewall handlers know how to handle.
 */
public:
	UnsupportedProtocolRequest(DIRECTION direction,
				std::string source, std::string dest,
				std::string message);
	std::string getType();

private:
};
#endif /* defined(__Final_WAShowalter__UnsupportedProtocolRequest__) */
