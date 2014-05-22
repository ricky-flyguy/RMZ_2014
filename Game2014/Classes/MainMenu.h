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

using namespace cocos2d;

class MainMenu : public RMZScene
{
    
public:
    
    static cocos2d::Scene* createScene();
    
        virtual bool init();
    
    void onPlay(Object* sender);
    void onOptions(Object* sender);
	void onHighScore(Object* sender);
    void onExit(Object* sender);
	//void RMZScene::onExit(Object* sender);
    
    CREATE_FUNC(MainMenu);

};

#endif /* defined(__Game2014__MainMenu__) */
