#include "Civilian.h"


Civilian::Civilian(void)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->init();
}

bool Civilian::init()
{
	this->fSpeed = 1.5f;
	return true;
}

Civilian* Civilian::create(const std::string &filename, int iNewScoreValue, Point* pPosition)
{
	Civilian* cNew = new Civilian();

	if (cNew && cNew->initWithFile(filename))
	{
		cNew->autorelease();
		cNew->setScale(0.25f);
		cNew->setPosition(*pPosition);
		cNew->setTag(2);

		PhysicsBody *pbBody = PhysicsBody::createBox(cNew->getBoundingBox().size);
		pbBody->setMass(0.0f);
		pbBody->setDynamic(false);
		cNew->setPhysicsBody(pbBody);

		//Update the civilian (moving left to right /\ viseversa)
		cNew->schedule(schedule_selector(Civilian::update));

		return cNew;
	}
	CC_SAFE_DELETE(cNew);

	return NULL;
}

void Civilian::update(float fDeltaTime)
{
	if (this->getPosition().x - this->getBoundingBox().size.width/2  <= 0 || this->getPosition().x + this->getBoundingBox().size.width/2 >= screenSize.width) fSpeed = -fSpeed;
	this->setPosition(ccp(this->getPosition().x + fSpeed, this->getPosition().y));
}

Civilian::~Civilian(void)
{
}
