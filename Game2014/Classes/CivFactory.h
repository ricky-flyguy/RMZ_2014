#ifndef _CIV_FACTORY_H
#define _CIV_FACTORY_H

#include "cocos2d.h"
#include "Civilian.h"

class CivFactory : public Sprite
{
private:
	int iTime;

	void createNewCivilian(bool bRandom);
	enum enCivType
	{
		red, green, brown, purple, ENUM_TOTAL		//Different names to be added later
	};
public:
	virtual void update(float fDeltaTime);
	static Civilian* newCiv();
	CivFactory(void);
	~CivFactory(void);
};

#endif