/* --------------------------------------------------------------------------------

				Credits.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_Credits
#define Game2014_Credits

#include "RMZScene.h"

using namespace cocos2d;

class Credits : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	
	//void onExit(Object* sender);
	//RMZScene::onExit(Object* sender);

	CREATE_FUNC(Credits);

};

#endif // !Game2014_Credits