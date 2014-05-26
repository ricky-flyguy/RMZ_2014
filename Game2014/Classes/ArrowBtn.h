#ifndef ARROWBTN_H
#define ARROWBTN_H

#include "cocos2d.h"
#include "Player.h"

using namespace cocos2d;

class ArrowBtn : public Sprite
{
private:
	Size screenSize;
	Player* player;
	bool move;

public:
	enum Type { None, Left, Down, Right };

	Type type;

	static ArrowBtn* create(Point* pos, Type type, Player* player);

	EventListenerTouchOneByOne* touchListener;

	bool onTouchBegan(Touch* touch, Event* evt);
	void onTouchMoved(Touch* touch, Event* evt);
	void onTouchEnded(Touch* touch, Event* evt);

	virtual void update(float dt);

	bool init(Point* Pos);

	ArrowBtn(Player* player);
	~ArrowBtn(void);
};

#endif

