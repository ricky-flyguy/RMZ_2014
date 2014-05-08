#include "Civilian.h"


Civilian::Civilian(void)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->init();
}

bool Civilian::init()
{
	this->fSpeed = 3.5f;
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

		//cNew->schedule(schedule_selector(Civilian::update));

		return cNew;
	}
	CC_SAFE_DELETE(cNew);

	return NULL;
}

void Civilian::update(float fDeltaTime)
{
	this->setPosition(ccp(this->getPosition().x + fSpeed, this->getPosition().y));
}

Civilian::~Civilian(void)
{
}
