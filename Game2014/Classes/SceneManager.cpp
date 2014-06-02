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
    sceneManager = new Scene();
    
    sceneManager->addChild(SCREEN_MAIN->createScene(), 0, 0);
    sceneManager->addChild(SCREEN_OPT->createScene(), -1, 1);
    sceneManager->addChild(SCREEN_HIGHSCORE->createScene(), -2, 2);
    sceneManager->addChild(SCREEN_SOCIAL->createScene(), -3, 3);
    sceneManager->addChild(SCREEN_CREDITS->createScene(), -4, 4);
    
    Director::getInstance()->runWithScene(sceneManager->getChildByTag(0)->getScene());
    
}

void SceneManager::changeScene(int s)
{
    
    if(s == MAIN_MENU)
        Director::getInstance()->pushScene(sceneManager->getChildByTag(0)->getScene());
    
    if(s == OPTIONS)
        Director::getInstance()->pushScene(sceneManager->getChildByTag(1)->getScene());
    
    if(s == HIGHSCORE)
        Director::getInstance()->pushScene(sceneManager->getChildByTag(2)->getScene());
    
    if(s == SOCIAL)
        Director::getInstance()->pushScene(sceneManager->getChildByTag(3)->getScene());
    
    if(s == CREDITS)
        Director::getInstance()->pushScene(sceneManager->getChildByTag(4)->getScene());
    
}



