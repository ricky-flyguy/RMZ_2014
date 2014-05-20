#ifndef _CIVILIAN_H
#define _CIVILIAN_H

#include "cocos2d.h"

using namespace cocos2d;

class Civilian : public Sprite
{
private:
	float fSpeed;
	bool bMovingRight;
	//Point* pPosition;
	Size screenSize;
	int iScoreValue;

public:
	static Civilian* create(const std::string &filename, int iNewScoreValue, bool bMovingRight, float fSpeed);
	virtual void update(float fDeltaTime);

	Civilian(float fnewSpeed, bool bnewMovement);
	~Civilian(void);
};

#endif