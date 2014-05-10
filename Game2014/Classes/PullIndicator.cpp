#include "PullIndicator.h"
#include "HelloWorldScene.h"

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

		this->arrow = Sprite::create("arrow.png");
		this->arrow->setScale(0.05f);

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
		//p->helloWrld = *world;
		return p;
	}

	CC_SAFE_DELETE(p);

	return NULL;
}

void PullIndicator::input()
{
	this->touchListener = EventListenerTouchOneByOne::create();
	//this->touchListener->setSwallowTouches(true);
	p = new Point(); // force


		this->touchListener->onTouchBegan = [&](Touch* touch, Event* evt)
		{
			EventTouch* e = (EventTouch*) evt;

			this->setPosition(touch->getLocation());

			return true;
		};

		this->touchListener->onTouchMoved = [&](Touch* touch, Event* evt)
		{
			EventTouch* e = (EventTouch*) evt;

			float maxDist = this->radius * 5; //300
			float prcnt;

			this->_offset = (touch->getLocation() - this->_pivot);

			if(this->_offset.getLength() >= maxDist)
			{
				prcnt = this->_offset.getLength()/maxDist;
				this->setPosition(*Point::clampMagnitude(&this->_offset, 50) + this->_pivot);
				*p = ccp(-this->_offset.x, -this->_offset.y);
				this->arrow->setPosition(*Point::clampMagnitude(p, 50) + this->_pivot);
				
				if (this->_offset.x <= 0)
					this->arrow->setRotation(RMZHelper::calculateAngle(_pivot, touch->getLocation()));
				else
					this->arrow->setRotation(-RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
				//free(&temp); // Possible mem leak!
			}
			else if (this->_offset.getLength() < maxDist)
			{
				prcnt = this->_offset.getLength()/maxDist;
				this->setPosition(*Point::clampMagnitude(&this->_offset, 50 * prcnt) + this->_pivot);
				*p = ccp(-this->_offset.x, -this->_offset.y);
				this->arrow->setPosition(*Point::clampMagnitude(p, 50 * prcnt) + this->_pivot);


				if (this->_offset.x <= 0)
					this->arrow->setRotation(RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
				else
					this->arrow->setRotation(-RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
				//free(&temp); // Possible mem leak!
			}

			//free(e);
			//CC_SAFE_DELETE(p);
			//CC_SAFE_DELETE(e);
		};

		this->touchListener->onTouchEnded = [&](Touch* touch, Event* evt)
		{
			HelloWorld::addBalloon(&this->_pivot, p);
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