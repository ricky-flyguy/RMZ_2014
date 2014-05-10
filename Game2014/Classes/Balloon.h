#ifndef _BALLOON_H
#define _BALLOON_H

#include "cocos2d.h"

using namespace cocos2d;

class Balloon : public Sprite
{
private:
	Point* velocity;
	Size screenSize;
	float gravity;
	void input();

public:

	static Balloon* create(Point* pos);
	static Balloon* createWithForce(Point* pos, Point* force);
	virtual void update(float dt);

	bool onContactBegin(const PhysicsContact& contact);
	bool init();

	Balloon(void);
	~Balloon(void);
};


#endif