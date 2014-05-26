/* --------------------------------------------------------------------------------

				HighScore.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#ifndef Game2014_HighScore
#define Game2014_HighScore

#include "RMZScene.h"

class HighScore : public Layer
{
public:

	void Clear();

	//return? getHighScores();
    
    static Scene* createScene();
    
    virtual bool init();

	HighScore(void);
	~HighScore(void);
};
#endif //Game2014_HighScore
