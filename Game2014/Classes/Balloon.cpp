#include "Balloon.h"
#include "HelloWorldScene.h"
#include "Player.h"

Balloon::Balloon(void)
{
	screenSize = Director::getInstance()->getVisibleSize();
}


Balloon* Balloon::create(Point* pos)
{
	Balloon* b = new Balloon();

	if (b && b->initWithFile("balloon.png"))
	{
		// Set auto release.
		b->autorelease();
		// Set Scale
		b->setScale(0.15f);		

		// CHANGE TO A DEFINED NUMBER AFTER
		b->setTag(0);
		auto body = PhysicsBody::createCircle(b->getBoundingBox().size.width/2.5f);
		body->setMass(1);
		body->setDynamic(true);
		b->setPhysicsBody(body);

		// Set Position
		b->setPosition(*pos);
		
		// Setup Event Listener
		//b->input();

		b->schedule(schedule_selector(Balloon::update));		

		return b;
	}
	CC_SAFE_DELETE(b);

	return NULL;
}

Balloon* Balloon::createWithForce(Point* pos, Point* force)
{
	Balloon* b = new Balloon();

	if (b && b->initWithFile("balloon.png"))
	{
		// Set auto release.
		b->autorelease();
		// Set Scale
		b->setScale(0.15f);		
		
		// Set Position
		b->setPosition(*pos);

		// CHANGE TO A DEFINED NUMBER AFTER
		//this->setTag(0);
		auto body = PhysicsBody::createCircle(b->getBoundingBox().size.width/2.5f);
		body->setMass(1);
		body->setDynamic(true);
		body->setContactTestBitmask(2);
		body->setCategoryBitmask(0x01); //0001
		b->setPhysicsBody(body);
		
		// give forces
		b->getPhysicsBody()->applyImpulse(*force);

		b->schedule(schedule_selector(Balloon::update));

		return b;
	}
	CC_SAFE_DELETE(b);

	return NULL;
}

void Balloon::input()
{
	//contactListener = EventListenerPhysicsContact::create();
	//contactListener->onContactBegin = CC_CALLBACK_2(Balloon::onContactBegin, this);
	//this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void Balloon::update(float dt)
{	
	//this->setPosition(ccp(this->getPosition().x, this->getPosition().y + (0.5 * -(gravity *gravity))));
	//this->checkCollision();
	//CCLog("Updating: ");
}
void Balloon::setCivilian(Civilian* civ)
{
	this->civ = civ;
}

void Balloon::checkCollision()
{
	if (this->getBoundingBox().intersectsRect(this->civ->boundingBox()))
	{
		this->removeFromParent();
	}
}


bool Balloon::onTouchBegan(Touch* touch, Event* evt)
{
	auto balloon = static_cast<Balloon*>(evt->getCurrentTarget());

	Point loc = balloon->convertToNodeSpace(touch->getLocation());
	Size s = balloon->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(loc))
	{

		balloon->removeFromParentAndCleanup(true);

		CCLog("Touched");
	}
	return false;
}

bool Balloon::onContactBegin(PhysicsContact& contact)
{
	auto balloon = static_cast<Balloon*>(contact.getCurrentTarget());
	
	//if (obj1->getTag() != obj2->getTag())
	//{
		//obj1->removeFromParent();
/*
		Event e = contact;

		auto balloon = static_cast<Balloon*>(e.getCurrentTarget());

		contact.

		balloon->setVisible(false);*/
	//}

	//int tag = s->getTag();
	//CCLog("Contact tag: %d", obj1->getTag());
	//CCLog("Contact tag: %d", obj2->getTag());

	//this->removeFromParent();

	//this->setVisible(false);
	//HelloWorld::removeBalloon(this);	
	return true;
}

Balloon::~Balloon(void)
{

}