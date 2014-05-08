#ifndef _CIVILIAN_H
#define _CIVILIAN_H

#include "cocos2d.h"

using namespace cocos2d;

class Civilian : public Sprite
{
private:
	float fSpeed;
	//Point* pPosition;
	Size screenSize;
	int iScoreValue;

public:
	static Civilian* create(const std::string &filename, int iNewScoreValue, Point* pPosition);
	virtual void update(float fDeltaTime);
	bool init();

	Civilian(void);
	~Civilian(void);
};

#endif