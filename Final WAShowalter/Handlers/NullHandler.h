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
public:
	void handleRequest(Request);
	void setSuccessor(std::unique_ptr<Handler> successor);

private:
};

#endif /* defined(__Final_WAShowalter__NullHandler__) */
