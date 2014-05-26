#ifndef _PULLINDICATOR_H
#define _PULLINDICATOR_H

#include "cocos2d.h"
#include "RMZHelper.h"
#include "Player.h"

using namespace cocos2d;

class PullIndicator : public Sprite
{
private:
	Size screenSize;
	Point _pivot;
	Point _offset;
	Point* p; // force
	float prcnt;
	Player* _player;
	float halfOfScreenWidth;

	Layer* layer;

	EventListenerTouchOneByOne* touchListener;

	bool init(Point* pos);
	void input();

public:
	
	float radius;

	Sprite* arrow;

	static PullIndicator* create(Point* pos, Player* player, Layer* layer);
	virtual void update(float dt);	
	bool onTouchBegan(Touch* touch, Event* evt);
	void onTouchMoved(Touch* touch, Event* evt);
	Point* onTouchEnded(Touch* touch, Event* evt);
	
	PullIndicator(Point* pos);
	PullIndicator();
	~PullIndicator(void);
};

#endif