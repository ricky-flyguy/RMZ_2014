//
//  MainMenu.h
//  Game2014
//
//  Created by The Matrix on 2014-05-07.
//
//

#ifndef __Game2014__MainMenu__
#define __Game2014__MainMenu__

#include "RMZScene.h"

class MainMenu : public RMZScene
{
    
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void onPlay(Object* sender);
    void onOptions(Object* sender);
	void onHighScore(Object* sender);
	void onSocial(Object* sender);
	void onCredits(Object* sender);
    void onExit(Object* sender);
    
    CREATE_FUNC(MainMenu);

};

#endif /* defined(__Game2014__MainMenu__) */
