/* --------------------------------------------------------------------------------

				RMZScene.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_RMZScene
#define Game2014_RMZScene

#include <iostream>
#include "cocos2d.h"

/* 1. Properties
	- Back Button.
	- Content TextField

	// Others
	- Each of RMZScenes child should be a singleton.
*/


using namespace cocos2d;

class RMZScene : public Layer
{
public:

	Sprite* bg;
	Label* title;

    static Scene* create();

   // virtual bool init() override;

	//virtual void onExit(Object* sender);

	RMZScene(void);
	~RMZScene(void);
};

#endif /* Game2014_RMZScene */

