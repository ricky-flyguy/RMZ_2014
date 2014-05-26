#include "ArrowBtn.h"


ArrowBtn::ArrowBtn(Player* player)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->player = player;
}

bool ArrowBtn::init(Point* pos)
{
	if (this->initWithFile("Arrow_Button.png"))
	{
		this->autorelease();

		this->setScale(0.5f);

		this->setPosition(*pos);
		this->move = false;
		
		return true;
	}
	return false;
}

ArrowBtn* ArrowBtn::create(Point* pos, Type type, Player* player)
{
	ArrowBtn* a = new ArrowBtn(player);

	if (a && a->init(pos))
	{
		a->schedule(schedule_selector(ArrowBtn::update));
		a->type = type;

		switch(type)
		{
		case None: break;
		case Left:
			a->setRotation(270);
			break;
		case Right:
			a->setRotation(90);
			break;
		case Down:
			a->setRotation(180);
			break;			
		}

		return a;	
	}

	CC_SAFE_DELETE(a);

	return NULL;
}

bool ArrowBtn::onTouchBegan(Touch* touch, Event* evt)
{
	if (this->getBoundingBox().containsPoint(touch->getLocation()))
	{
		move = true;
		CCLog("Touched Arrow");
		return true;
	}


	return false;
}
void ArrowBtn::onTouchMoved(Touch* touch, Event* evt)
{
	if (!this->getBoundingBox().containsPoint(touch->getLocation()))
		move = false;
	else move = true;
}
void ArrowBtn::onTouchEnded(Touch* touch, Event* evt)
{
	if (this->getBoundingBox().containsPoint(touch->getLocation()))
	{
		move = false;
		CCLog("Touched Arrow");
	}
}

void ArrowBtn::update(float dt)
{
	if (move)
	{
		switch(type)
		{
		case None:
			break;
		case Left:
			player->setPosition(player->getPosition().x - 2, player->getPosition().y);
			break;
		case Right:
			player->setPosition(player->getPosition().x + 2, player->getPosition().y);
			break;
		case Down:
			break;
		}
	}
}

ArrowBtn::~ArrowBtn(void)
{
}
