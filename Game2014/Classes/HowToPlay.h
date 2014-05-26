/* --------------------------------------------------------------------------------

				HowToPlay.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_HowToPlay
#define Game2014_HowToPlay

#include "RMZScene.h"

class HowToPlay : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void onExit(Object* sender);
	
	CREATE_FUNC(HowToPlay);
};

#endif // !Game2014_HowToPlay