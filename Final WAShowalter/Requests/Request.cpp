//
//  Request.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "Request.h"

DIRECTION Request::getDirection() {
	return _direction;
}
std::string Request::getSource() {
	return _source;
}
std::string Request::getDest() {
	return _dest;
}
std::string Request::getMessage() {
	return _message;
}

void Request::setDirection(DIRECTION direciton){
	_direction = direciton;
}
void Request::setSource(std::string source){
	_source = source;
}
void Request::setDest(std::string dest){
	_dest = dest;
}
void Request::setMessage(std::string message){
	_message = message;
}