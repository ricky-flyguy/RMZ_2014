#include "Player.h"


Player::Player(void)
{
	screenSize = Director::getInstance()->getVisibleSize();
	this->init();
}

bool Player::init()
{
	this->velocity = new Point(2, 5);

	//velocity->normalize();
	return true;
}

Player* Player::create(const std::string &filename, Point* pos)
{
	Player* p = new Player();

	if (p && p->initWithFile(filename))
	{
		// Set auto release.
		p->autorelease();
		// Set Scale
		p->setScale(0.25f);
		// Set Position
		p->setPosition(*pos);

		return p;
	}
	CC_SAFE_DELETE(p);

	return NULL;
}

void Player::update(float dt)
{
	//this->setPosition(ccp(this->getPosition().x + velocity->x, this->getPosition().y + velocity->y));
	clamp();
}

void Player::clamp()
{
	if (this->getPosition().x - this->getBoundingBox().size.width/2  <= 0 || this->getPosition().x + this->getBoundingBox().size.width/2 >= screenSize.width)
		velocity->x = -velocity->x;
	if (this->getPosition().y - this->getBoundingBox().size.height/2  <= 0 || this->getPosition().y + this->getBoundingBox().size.height/2 >= screenSize.height)
		velocity->y = -velocity->y;
}



Player::~Player(void)
{
}
