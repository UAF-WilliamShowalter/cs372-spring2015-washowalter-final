//
//  IPv4Request.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__IPv4Request__
#define __Final_WAShowalter__IPv4Request__

#include <stdio.h>
#include "Request.h"

class IPv4Request : public Request {
public:
	std::string getType();
	std::string getDirection();
	std::string getSource();
	std::string getDest();
	std::string getMessage();

private:
};


#endif /* defined(__Final_WAShowalter__IPv4Request__) */
