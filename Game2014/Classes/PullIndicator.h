#ifndef _PULLINDICATOR_H
#define _PULLINDICATOR_H

#include "cocos2d.h"

using namespace cocos2d;

class PullIndicator : public Sprite
{
private:
	Size screenSize;
	Point _pivot;
	Point _offset;

	EventListenerTouchOneByOne* touchListener;

	bool init(Point* pos);
	void input();

public:
	
	float radius;

	static PullIndicator* create(Point* pos);
	virtual void update(float dt);	
	
	PullIndicator(Point* pos);
	PullIndicator();
	~PullIndicator(void);
};

#endif