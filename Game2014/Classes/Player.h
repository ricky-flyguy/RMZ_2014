#ifndef _PLAYER_H
#define _PLAYER_H

#include "cocos2d.h"

using namespace cocos2d;

class Player : public Sprite
{
private:
	Point* velocity;
	Size screenSize;

	void clamp();

public:

	static Player* create(const std::string &filename, Point* pos);
	virtual void update(float dt);
	bool init();

	Player(void);
	~Player(void);
};

#endif

