//
//  UnsupportedProtocolRequest.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "UnsupportedProtocolRequest.h"

UnsupportedProtocolRequest::UnsupportedProtocolRequest(DIRECTION direction,
						 std::string source, std::string dest,
						 std::string message):_direction(direction),
_source(source),_dest(dest),_message(message){}

std::string UnsupportedProtocolRequest::getType() {
	return "IPv29902345987235807";
}
DIRECTION UnsupportedProtocolRequest::getDirection() {
	return _direction;
}
std::string UnsupportedProtocolRequest::getSource() {
	return _source;
}
std::string UnsupportedProtocolRequest::getDest() {
	return _dest;
}
std::string UnsupportedProtocolRequest::getMessage() {
	return _message;
}