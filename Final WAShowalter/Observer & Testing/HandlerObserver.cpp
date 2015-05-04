//
//  HandlerObserver.cpp
//  Final WAShowalter
//
//  Created by William Showalter on 15/05/03.
//  Copyright (c) 2015 William Showalter. All rights reserved.
//

#include "HandlerObserver.h"

void HandlerObserver::notify (std::string newLog){
	_logs << newLog << std::endl;
}
std::string HandlerObserver::getLogs (){
	return _logs.str();
}