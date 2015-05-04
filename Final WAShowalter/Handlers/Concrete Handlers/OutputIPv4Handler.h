//
//  OutputIPv4Handler.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__OutputIPv4Handler__
#define __Final_WAShowalter__OutputIPv4Handler__

#include <stdio.h>
#include "Handler.h"

class OutputIPv4Handler : public Handler {
public:
	void handleRequest(std::unique_ptr<Request> r);

private:
};
#endif /* defined(__Final_WAShowalter__OutputIPv4Handler__) */
