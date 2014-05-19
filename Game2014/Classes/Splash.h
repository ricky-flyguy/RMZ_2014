/* --------------------------------------------------------------------------------

				Splash.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_Splash
#define Game2014_Splash

#include "RMZScene.h"

using namespace cocos2d;

class Splash : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void onExit(Object* sender);
	//RMZScene::onExit(Object* sender);

	CREATE_FUNC(Splash);

};

#endif // !Game2014_Splash