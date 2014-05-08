#include "PullIndicator.h"

PullIndicator::PullIndicator()
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->radius = 50;
}

PullIndicator::PullIndicator(Point* pos)
{
	screenSize = Director::getInstance()->getVisibleSize();
	//this->init(pos);
}

bool PullIndicator::init(Point* pos)
{
	if (this->initWithFile("pull.png"))
	{
		this->autorelease();
	
		this->setPosition(*pos);
		
		this->setScale(0.25f);

		this->_pivot = *pos;

		this->input();

		return true;
	}
	
	return false;
}

PullIndicator* PullIndicator::create(Point* pos)
{
	PullIndicator* p = new PullIndicator();

	if (p && p->init(pos))
	{
		return p;
	}

	CC_SAFE_DELETE(p);

	return NULL;
}

void PullIndicator::input()
{
	this->touchListener = EventListenerTouchOneByOne::create();
		this->touchListener->setSwallowTouches(true);

		this->touchListener->onTouchBegan = [&](Touch* touch, Event* evt)
		{
			EventTouch* e = (EventTouch*) evt;

			this->setPosition(touch->getLocation());

			return true;
		};

		this->touchListener->onTouchMoved = [&](Touch* touch, Event* evt)
		{
			EventTouch* e = (EventTouch*) evt;

			this->_offset = touch->getLocation() - this->_pivot;
			
			if (this->_offset.getLength() > (this->radius *2))
				this->setPosition(*Point::clampMagnitude(&this->_offset, 50) + this->_pivot);
			else this->setPosition(touch->getLocation());
		};

		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void PullIndicator::update(float dt)
{
	//this->setPosition(ccp(this->getPosition().x, this->getPosition().y + (0.5 * -(gravity *gravity))));
	//clamp();
}




PullIndicator::~PullIndicator(void)
{

}