/* --------------------------------------------------------------------------------

				HighScore.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_HighScore
#define Game2014_HighScore

#include "RMZScene.h"

class HighScore : public RMZScene
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void Clear();
	void onExit(Object* sender);

	//return? getHighScores();

	CREATE_FUNC(HighScore);
};
#endif //Game2014_HighScore
