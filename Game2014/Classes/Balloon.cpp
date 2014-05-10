#include "Balloon.h"

Balloon::Balloon(void)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->init();
}

bool Balloon::init()
{
	//this->velocity = new Point(0, 5);
	//this->gravity = 2.5f;

	//this->input();

	return true;
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
		auto body = PhysicsBody::createCircle(b->getBoundingBox().size.width/2);
		body->setMass(1);
		body->setDynamic(true);
		b->setPhysicsBody(body);
		
		// Set Position
		b->setPosition(*pos);
		
		// Setup Event Listener
		b->input();

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
		b->setTag(0);
		auto body = PhysicsBody::createCircle(b->getBoundingBox().size.width/2);
		body->setMass(1);
		body->setDynamic(true);
		b->setPhysicsBody(body);		
		
		// Setup Event Listeners
		b->input();
		
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
	auto contactListener = EventListenerPhysicsContact::create();

	contactListener->onContactBegin = CC_CALLBACK_1(Balloon::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}

void Balloon::update(float dt)
{
	//this->setPosition(ccp(this->getPosition().x, this->getPosition().y + (0.5 * -(gravity *gravity))));
	//clamp();
}

bool Balloon::onContactBegin(const PhysicsContact& contact)
{
	return true;
}

Balloon::~Balloon(void)
{

}