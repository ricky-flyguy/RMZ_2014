#include "Balloon.h"

Balloon::Balloon(void)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->init();
}

bool Balloon::init()
{
	//this->velocity = new Point(0, 5);
	this->gravity = 2.5f;

	return true;
}

Balloon* Balloon::create(const std::string &filename, Point* pos)
{
	Balloon* b = new Balloon();

	if (b && b->initWithFile(filename))
	{
		// Set auto release.
		b->autorelease();
		// Set Scale
		b->setScale(0.15f);
		// Set Position
		b->setPosition(*pos);

		b->schedule(schedule_selector(Balloon::update));

		return b;
	}
	CC_SAFE_DELETE(b);

	return NULL;
}


void Balloon::update(float dt)
{
	this->setPosition(ccp(this->getPosition().x, this->getPosition().y + (0.5 * -(gravity *gravity))));
	//clamp();
}

Balloon::~Balloon(void)
{

}