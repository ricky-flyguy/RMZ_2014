#include "CivFactory.h"


CivFactory::CivFactory(void)
{
	iTime = 0;
}


void CivFactory::createNewCivilian(bool bRandom)
{
	if(bRandom)
	{
		Civilian* civRand = Civilian::create("civ_diver_1.png", 10, true, 0.5f);
		this->addChild(civRand, 100);
	}
	else
	{

	}
}

Civilian* CivFactory::newCiv()
{
	std::ostringstream osTextureName;
	osTextureName << "civ_diver_" << rand() % ENUM_TOTAL << ".png";

	float fSpeed = (rand() / (float)RAND_MAX * 4) + 1;
	//CCLog("Speed: %f", fSpeed);
	Civilian* civRand = Civilian::create(osTextureName.str(), 10, rand() % 2, fSpeed);
	
	return civRand;
}

void CivFactory::update(float fDeltaTime)
{
	iTime += 1;
	switch (iTime / 60)
	{
	case 1:
		createNewCivilian(true);
		break;
	case 2:
		createNewCivilian(false);
		break;
	case 3:
		iTime = 0;
		break;
	}
	
	
	CCLog("Time: %i", iTime);
}

CivFactory::~CivFactory(void)
{
}
