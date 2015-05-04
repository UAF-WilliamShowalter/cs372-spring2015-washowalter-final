//
//  RequestFactory.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__RequestFactory__
#define __Final_WAShowalter__RequestFactory__

#include <stdio.h>
#include <string>
#include "Request.h"
#include "IPv4Request.h"
#include "IPv6Request.h"
#include "UnsupportedProtocolRequest.h"

#include <memory>

class RequestFactory {
public:
	static std::unique_ptr<Request> makeRequest(std::string type, DIRECTION direction, std::string source, std::string dest, std::string message);
};

#endif /* defined(__Final_WAShowalter__RequestFactory__) */
