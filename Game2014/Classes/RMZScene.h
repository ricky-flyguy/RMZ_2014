/* --------------------------------------------------------------------------------

				RMZScene.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_RMZScene
#define Game2014_RMZScene

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class RMZScene : public Layer
{
public:

	Sprite* bg;
	Label* title;

	static cocos2d::Scene* createScene();

	RMZScene(void);
	~RMZScene(void);
};

#endif /* Game2014_RMZScene */

