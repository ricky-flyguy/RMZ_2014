/* --------------------------------------------------------------------------------

				Options.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/


#ifndef Game2014_Options
#define Game2014_Options

#include "RMZScene.h"

class Options : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void onAudio(Object* sender);
	void onRMZLINK(Object* sender);
	void onExit(Object* sender);
	

	CREATE_FUNC(Options);

};
#endif // !Game2014_Options



