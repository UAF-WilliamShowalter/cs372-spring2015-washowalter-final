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

class Request {
public:
	virtual ~Request() = default;
	virtual std::string getType() = 0;
	virtual std::string getDirection() = 0;
	virtual std::string getSource() = 0;
	virtual std::string getDest() = 0;
	virtual std::string getMessage() = 0;

private:
};

#endif /* defined(__Final_WAShowalter__Request__) */
