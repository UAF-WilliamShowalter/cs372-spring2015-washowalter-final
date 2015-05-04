//
//  Request.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__Request__
#define __Final_WAShowalter__Request__

#include <stdio.h>
#include <string>

enum DIRECTION {INPUT, OUTPUT, FORWARD};
/*
 Types for getSource, getDest would be of an abstract Address classes to support IPv4 & IPv6
 */

class Request {
public:
	virtual ~Request() = default;
	virtual std::string getType() = 0;
	virtual DIRECTION getDirection();
	virtual std::string getSource();
	virtual std::string getDest();
	virtual std::string getMessage();

	void setDirection(DIRECTION);
	void setSource(std::string);
	void setDest(std::string);
	void setMessage(std::string);
private:
	DIRECTION _direction;
	std::string _source;
	std::string _dest;
	std::string _message;
};

#endif /* defined(__Final_WAShowalter__Request__) */
