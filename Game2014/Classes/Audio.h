/* --------------------------------------------------------------------------------

				Audio.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_Audio
#define Game2014_Audio

#include "RMZScene.h"

using namespace cocos2d;

class Audio : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void Mute();
	void onExit(Object* sender);

	CREATE_FUNC(Audio);

};

#endif // !Game2014_Audio