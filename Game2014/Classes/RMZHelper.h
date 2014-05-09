#ifndef _RMZHELPER_H
#define _RMZHELPER_H

#include "cocos2d.h"

using namespace cocos2d;

class RMZHelper
{
public:

	static float calculateAngle(const Point origin, const Point offset);

	RMZHelper(void);
	~RMZHelper(void);
};

#endif