//
//  IPv6Request.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "IPv6Request.h"

IPv6Request::IPv6Request(DIRECTION direction,
						 std::string source, std::string dest,
						 std::string message):_direction(direction),
_source(source),_dest(dest),_message(message){}

std::string IPv6Request::getType() {
	return "IPv6";
}
DIRECTION IPv6Request::getDirection() {
	return _direction;
}
std::string IPv6Request::getSource() {
	return _source;
}
std::string IPv6Request::getDest() {
	return _dest;
}
std::string IPv6Request::getMessage() {
	return _message;
}