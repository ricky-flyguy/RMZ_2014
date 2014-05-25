#include "PullIndicator.h"
#include "HelloWorldScene.h"

PullIndicator::PullIndicator()
{
	screenSize = Director::getInstance()->getVisibleSize();
	halfOfScreenWidth = screenSize.width/2;
	this->radius = 25;
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
		
		this->setScale(0.1f);

		this->_pivot = *pos;

		this->arrow = Sprite::create("arrow.png");
		this->arrow->setScale(0.05f);

		this->input();

		return true;
	}
	
	return false;
}

PullIndicator* PullIndicator::create(Point* pos, Player* player, Layer* layer)
{
	PullIndicator* p = new PullIndicator();

	if (p && p->init(pos))
	{
		p->_player = player;
		p->layer = layer;
		//p->helloWrld = *world;
		return p;
	}

	CC_SAFE_DELETE(p);

	return NULL;
}

void PullIndicator::input()
{
	//this->touchListener = EventListenerTouchOneByOne::create();
	//this->touchListener->onTouchBegan = CC_CALLBACK_2(PullIndicator::onTouchBegan, this);
	//this->touchListener->onTouchMoved = CC_CALLBACK_2(PullIndicator::onTouchMoved, this);
	//this->touchListener->onTouchEnded = CC_CALLBACK_2(PullIndicator::onTouchEnded, this);
	//this->touchListener->setSwallowTouches(true);
	p = new Point(); // force


	//this->touchListener->onTouchBegan = [&](Touch* touch, Event* evt)
	//{
	//	EventTouch* e = (EventTouch*) evt;

	//	this->setPosition(touch->getLocation());

	//	return true;
	//};



	//this->touchListener->onTouchMoved = [&](Touch* touch, Event* evt)
	//{
	//	EventTouch* e = (EventTouch*) evt;

	//	float maxDist = this->radius * 4; //200

	//	this->_offset = (touch->getLocation() - this->_pivot);

	//	if(this->_offset.getLength() >= maxDist)
	//	{
	//		prcnt = 1;
	//		this->setPosition(RMZHelper::clampMagnitude(&this->_offset, this->radius) + this->_pivot);
	//		*p = ccp(-this->_offset.x, -this->_offset.y);
	//		
	//		this->arrow->setPosition(RMZHelper::clampMagnitude(p, this->radius) + this->_player->getPosition());
	//		*p = RMZHelper::clampMagnitude(p, this->radius); 

	//		if (this->_offset.x <= 0)
	//			this->arrow->setRotation(RMZHelper::calculateAngle(_pivot, touch->getLocation()));
	//		else
	//			this->arrow->setRotation(-RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
	//		//free(&temp); // Possible mem leak!
	//	}
	//	else if (this->_offset.getLength() < maxDist)
	//	{
	//		prcnt = this->_offset.getLength()/maxDist;
	//		this->setPosition(RMZHelper::clampMagnitude(&this->_offset, this->radius * prcnt) + this->_pivot);
	//		*p = ccp(-this->_offset.x, -this->_offset.y);
	//		
	//		this->arrow->setPosition(RMZHelper::clampMagnitude(p, this->radius * prcnt) + this->_player->getPosition());
	//		*p = RMZHelper::clampMagnitude(p, this->radius * prcnt);

	//		if (this->_offset.x <= 0)
	//			this->arrow->setRotation(RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
	//		else
	//			this->arrow->setRotation(-RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
	//		//free(&temp); // Possible mem leak!
	//	}

	//	//free(e);
	//	//CC_SAFE_DELETE(p);
	//	//CC_SAFE_DELETE(e);
	//};

	//this->touchListener->onTouchEnded = [&](Touch* touch, Event* evt)
	//{
	//	*p = Point(p->x * 10, p->y * 10);

	//	//layer->addBalloon(_player->getPosition(), p);
	//};

	//this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void PullIndicator::update(float dt)
{
	//this->setPosition(ccp(this->getPosition().x, this->getPosition().y + (0.5 * -(gravity *gravity))));
	//clamp();
}

bool PullIndicator::onTouchBegan(Touch* touch, Event* evt)
{
	EventTouch* e = (EventTouch*) evt;

	//this->setPosition(touch->getLocation());

	return true;
}
void PullIndicator::onTouchMoved(Touch* touch, Event* evt)
{

	if (touch->getLocation().x > halfOfScreenWidth) return;
		EventTouch* e = (EventTouch*) evt;

		float maxDist = this->radius * 4; //200

		this->_offset = (touch->getLocation() - this->_pivot);

		if(this->_offset.getLength() >= maxDist)
		{
			prcnt = 1;
			this->setPosition(RMZHelper::clampMagnitude(&this->_offset, this->radius) + this->_pivot);
			*p = ccp(-this->_offset.x, -this->_offset.y);
			
			this->arrow->setPosition(RMZHelper::clampMagnitude(p, this->radius) + this->_player->getPosition());
			*p = RMZHelper::clampMagnitude(p, this->radius); 

			if (this->_offset.x <= 0)
				this->arrow->setRotation(RMZHelper::calculateAngle(_pivot, touch->getLocation()));
			else
				this->arrow->setRotation(-RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
			//free(&temp); // Possible mem leak!
		}
		else if (this->_offset.getLength() < maxDist)
		{
			prcnt = this->_offset.getLength()/maxDist;
			this->setPosition(RMZHelper::clampMagnitude(&this->_offset, this->radius * prcnt) + this->_pivot);
			*p = ccp(-this->_offset.x, -this->_offset.y);
			
			this->arrow->setPosition(RMZHelper::clampMagnitude(p, this->radius * prcnt) + this->_player->getPosition());
			*p = RMZHelper::clampMagnitude(p, this->radius * prcnt);

			if (this->_offset.x <= 0)
				this->arrow->setRotation(RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
			else
				this->arrow->setRotation(-RMZHelper::calculateAngle(this->_pivot, touch->getLocation()));
			//free(&temp); // Possible mem leak!
		}

		//free(e);
		//CC_SAFE_DELETE(p);
		//CC_SAFE_DELETE(e);
}
Point* PullIndicator::onTouchEnded(Touch* touch, Event* evt)
{
	*p = Point(p->x * 10, p->y * 10);

	return (p);
}



PullIndicator::~PullIndicator(void)
{

}