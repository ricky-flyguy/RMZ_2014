/* --------------------------------------------------------------------------------

				Social.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_Social
#define Game2014_Social

#include "RMZScene.h"

class Social : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	int ShareScoreFB();
	void onExit(Object* sender);

	CREATE_FUNC(Social);
};

#endif // !Game2014_Social