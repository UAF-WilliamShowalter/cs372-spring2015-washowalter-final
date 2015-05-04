//
//  IPv6Request.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "IPv6Request.h"

IPv6Request::IPv6Request(DIRECTION direction, std::string source,
						 std::string dest, std::string message)
{
	setDirection(direction);
	setSource(source);
	setDest(dest);
	setMessage(message);
}

std::string IPv6Request::getType() {
	return "IPv6";
}