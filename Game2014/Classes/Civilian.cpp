#include "Civilian.h"


Civilian::Civilian(float fnSpeed, bool bnewMovement)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->bMovingRight = bnewMovement;

	if(bMovingRight) this->fSpeed = fnSpeed;
	else this->fSpeed = -fnSpeed;
	
}

Civilian* Civilian::create(const std::string &filename, int iNewScoreValue, bool bMovingRight, float fSpeed)
{
	Civilian* cNew = new Civilian(fSpeed, bMovingRight);

	if (cNew && cNew->initWithFile(filename))
	{
		if(bMovingRight) cNew->setPosition(ccp(0, Director::getInstance()->getVisibleSize().height/6));
		else cNew->setPosition(ccp(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height/6));

		cNew->autorelease();
		cNew->setScale(0.25f);
		
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
	this->setPosition(ccp(this->getPosition().x + fSpeed, this->getPosition().y));
	if (!bMovingRight && (this->getPosition().x - this->getBoundingBox().size.width/2  <= 0)) this->removeFromParent();
	else if (bMovingRight && (this->getPosition().x + this->getBoundingBox().size.width/2 >= screenSize.width)) this->removeFromParent();	
}

Civilian::~Civilian(void)
{
}
