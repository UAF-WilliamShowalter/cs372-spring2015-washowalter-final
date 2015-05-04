//
//  IPv6Request.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__IPv6Request__
#define __Final_WAShowalter__IPv6Request__

#include <stdio.h>
#include "Request.h"

class IPv6Request : public Request {
	/*
	 Because this example uses strings for all fields, IPv4 and IPv6 are identical.
	 But a fully flushed out version would have 32-bit address fields in IPv4 and
		128bit address fields in IPv6, along with other changes.
	 */
public:
	IPv6Request(DIRECTION direction,
				std::string source, std::string dest,
				std::string message);
	std::string getType();
	
private:
};

#endif /* defined(__Final_WAShowalter__IPv6Request__) */
