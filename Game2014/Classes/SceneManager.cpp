//
//  SceneManager.cpp
//  Game2014
//
//  Created by The Matrix on 2014-05-20.
//
//

#include "SceneManager.h"


SceneManager* SceneManager::instance = NULL;



SceneManager* SceneManager::sceneMgr()
{
    if(!instance)
        instance = new SceneManager();

    
    return instance;
}

SceneManager::SceneManager()
{
    init();
}


SceneManager::~SceneManager()
{
}

void SceneManager::init()
{
    cout << "initing" << endl;
    SCREEN_MAIN->createScene();
    SCREEN_GAME->createScene();
   SCREEN_OPT->createScene();
}

void SceneManager::changeScene(int s)
{
   

    
    if(s == GAME)
        Director::getInstance()->pushScene(SCREEN_GAME->createScene());
    
    if(s == MAIN_MENU)
        Director::getInstance()->pushScene(SCREEN_MAIN->createScene());
    
    if(s == OPTIONS)
        Director::getInstance()->pushScene(SCREEN_OPT->createScene());
    
}



