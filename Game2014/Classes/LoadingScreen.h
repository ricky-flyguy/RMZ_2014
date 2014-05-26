/* --------------------------------------------------------------------------------

				LoadingScreen.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_LoadingScreen
#define Game2014_LoadingScreen

#include "RMZScene.h"

class LoadingScreen : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void onExit(Object* sender);

	CREATE_FUNC(LoadingScreen);

};

#endif // !Game2014_LoadingScreen