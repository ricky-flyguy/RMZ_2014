//
//  SceneManager.h
//  Game2014
//
//  Created by The Matrix on 2014-05-25.
//
//

#ifndef __Game2014__SceneManager__
#define __Game2014__SceneManager__


#include <iostream>

#include "cocos2d.h"


#include "HelloWorldScene.h"

#include "MainMenu.h"

#include "Options.h"

#include "HighScore.h"

#include "Social.h"

#include "Credits.h"

#include "SceneManager.h"

 
using namespace std;
using namespace cocos2d;


static Scene* sceneManager;
static MainMenu* SCREEN_MAIN;
static Options* SCREEN_OPT;
static HelloWorld* SCREEN_GAME;
static HighScore* SCREEN_HIGHSCORE;
static Social* SCREEN_SOCIAL;
static Credits* SCREEN_CREDITS;



class SceneManager
{
private:
    
    
    // RMZScene currentScene;

        static SceneManager* instance;
    
    std::list<RMZScene> sceneList;
    
    
public:
    void changeScene(int s);
    
    const int MAIN_MENU = 0;
    const int OPTIONS = 1;
    const int HIGHSCORE = 2;
    const int SOCIAL = 3;
    const int CREDITS = 4;
    
    static SceneManager* sceneMgr();
    

    
    void init();
    
    
    SceneManager(void);
    ~SceneManager(void);
    
};

#endif /* defined(__Game2014__SceneManager__) */
