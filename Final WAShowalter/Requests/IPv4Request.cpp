//
//  IPv4Request.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "IPv4Request.h"

IPv4Request::IPv4Request(DIRECTION direction,
			std::string source, std::string dest,
			std::string message):_direction(direction),
			_source(source),_dest(dest),_message(message){}

std::string IPv4Request::getType() {
	return "IPv4";
}
DIRECTION IPv4Request::getDirection() {
	return _direction;
}
std::string IPv4Request::getSource() {
	return _source;
}
std::string IPv4Request::getDest() {
	return _dest;
}
std::string IPv4Request::getMessage() {
	return _message;
}