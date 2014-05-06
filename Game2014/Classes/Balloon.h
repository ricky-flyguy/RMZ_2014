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

public:

	static Balloon* create(const std::string &filename, Point* pos);
	virtual void update(float dt);
	bool init();

	Balloon(void);
	~Balloon(void);
};


#endif