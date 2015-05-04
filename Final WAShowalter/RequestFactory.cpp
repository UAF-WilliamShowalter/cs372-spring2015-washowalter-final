//
//  RequestFactory.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "RequestFactory.h"

#include <memory>
using std::make_shared;
using std::make_unique;
using std::unique_ptr;
using std::shared_ptr;
using std::move;

std::unique_ptr<Request> RequestFactory::makeRequest(std::string type, DIRECTION direction, std::string source, std::string dest, std::string message)
	{
		if (type == "IPv4") {
			return make_unique<IPv4Request>(direction,source,dest,message);
		}
		else if (type == "IPv6") {
			return make_unique<IPv6Request>(direction,source,dest,message);
		}
		else
			return make_unique<UnsupportedProtocolRequest>(direction,source,dest,message);
	}
