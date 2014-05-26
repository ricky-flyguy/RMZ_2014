//
//  MainMenu.h
//  Game2014
//
//  Created by The Matrix on 2014-05-07.
//
//
//
//  Created by The Matrix on 2014-05-07.
//
//

#ifndef __Game2014__MainMenu__
#define __Game2014__MainMenu__

#include <iostream>
#include "cocos2d.h"

#include "Options.h"

#include "HighScore.h"

#include "HelloWorldScene.h"


using namespace cocos2d;

class MainMenu : public Layer
{
private:
    
   // static Scene* scene;
    
public:
    
 
    
    // static Scene* getCurrentScene();
    
     static Scene* createScene();
    
    virtual bool init();
    
    void onPlay(Object* sender);
    void onOptions(Object* sender);
    void onExit(Object* sender);
    void onHighScore(Object* sender);
    
    CREATE_FUNC(MainMenu);
    
};


#endif /* defined(__Game2014__MainMenu__) */
