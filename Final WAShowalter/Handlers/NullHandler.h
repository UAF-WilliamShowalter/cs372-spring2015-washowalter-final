//
//  NullHandler.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__NullHandler__
#define __Final_WAShowalter__NullHandler__

#include <stdio.h>
#include "Handler.h"

class NullHandler : public Handler {
	/*
	 Null Object design pattern.
	 Handler to be set as successor when there is no next handler.
	 */
public:
	void handleRequest(std::unique_ptr<Request> r);

private:
};

#endif /* defined(__Final_WAShowalter__NullHandler__) */
