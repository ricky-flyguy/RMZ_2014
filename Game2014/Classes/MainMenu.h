//
//  MainMenu.h
//  Game2014
//
//  Created by The Matrix on 2014-05-07.
//
//

#ifndef __Game2014__MainMenu__
#define __Game2014__MainMenu__

#include <iostream>

#include "cocos2d.h"

using namespace cocos2d;

class MainMenu : public cocos2d::Layer
{
    
public:
    

    
    static cocos2d::Scene* createScene();
    
        virtual bool init();
    
    void onPlay(Object* sender);
    void onOptions(Object* sender);
    void onExit(Object* sender);
    
    CREATE_FUNC(MainMenu);

};

#endif /* defined(__Game2014__MainMenu__) */
