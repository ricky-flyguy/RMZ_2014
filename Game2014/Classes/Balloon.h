#ifndef _BALLOON_H
#define _BALLOON_H

#include "cocos2d.h"
#include "Civilian.h"

using namespace cocos2d;

class Balloon : public Sprite
{
private:
	Point* velocity;
	Size screenSize;
	float gravity;
	void input();
	float time;
	Civilian* civ;

	//EventListenerPhysicsContact* contactListener;

public:

	static Balloon* create(Point* pos);
	static Balloon* createWithForce(Point* pos, Point* force);
	virtual void update(float dt);
	void setCivilian(Civilian* civ);

	void checkCollision();

	bool onContactBegin(PhysicsContact& contact);
	bool onTouchBegan(Touch* touch, Event* evt);

	Balloon(void);
	~Balloon(void);
};


#endif