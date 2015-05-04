//
//  HandlerObserver.h
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#ifndef __Final_WAShowalter__HandlerObserver__
#define __Final_WAShowalter__HandlerObserver__

#include <stdio.h>
#include <string>
#include <sstream>

/*
 Takes logs from "Firewall" handlers about their actions. 
 Emulates a syslog service used by the handlers.
*/

class HandlerObserver {
public:
	void notify (std::string newLog);
	std::string getLogs ();
private:
	std::stringstream _logs;
};

#endif /* defined(__Final_WAShowalter__HandlerObserver__) */