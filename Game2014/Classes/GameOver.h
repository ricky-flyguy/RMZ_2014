/* --------------------------------------------------------------------------------

				GameOver.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_GameOver
#define Game2014_GameOver

#include "RMZScene.h"

using namespace cocos2d;

class GameOver : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void onExit(Object* sender);
	
	CREATE_FUNC(GameOver);

};

#endif // !Game2014_GameOver