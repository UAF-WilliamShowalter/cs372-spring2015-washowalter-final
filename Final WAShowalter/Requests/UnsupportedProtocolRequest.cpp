//
//  UnsupportedProtocolRequest.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "UnsupportedProtocolRequest.h"

UnsupportedProtocolRequest::UnsupportedProtocolRequest
			(DIRECTION direction, std::string source,
				std::string dest, std::string message)
{
	setDirection(direction);
	setSource(source);
	setDest(dest);
	setMessage(message);
}

std::string UnsupportedProtocolRequest::getType() {
	return "IPv29902345987235807";
}