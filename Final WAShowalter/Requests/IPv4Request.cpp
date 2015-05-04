//
//  IPv4Request.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "IPv4Request.h"

IPv4Request::IPv4Request(DIRECTION direction, std::string source,
			std::string dest, std::string message)
{
	setDirection(direction);
	setSource(source);
	setDest(dest);
	setMessage(message);
}

std::string IPv4Request::getType()
{
	return "IPv4";
}