//
//  MainMenu.cpp
//  Game2014
//
//  Created by The Matrix on 2014-05-07.
//
//

#include "MainMenu.h"
#include "Options.h"
#include "HighScore.h"
#include "HelloWorldScene.h"
#include "Credits.h"
#include "Social.h"
#include "SceneManager.h"

Scene* MainMenu::createScene()
{
    Scene *scene = NULL;    
    do {
        
        scene = Scene::create(); //create the scene
       // CC_BREAK_IF(!scene); //if there is no scene, break
        
        MainMenu *layer = MainMenu::create(); //create a layer
        CC_BREAK_IF(!layer);
        
        //add layer to the scene
        scene->addChild(layer);
        
    } while (0);
    
    return scene;
}
/*
Scene* MainMenu::getCurrentScene()
{
    if(scene != NULL)
        return scene;
}
 */

bool MainMenu::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!Layer::init());
      
        //enable touch
        this->setTouchEnabled(true);
        
        //Main menu items
        MenuItemFont* item1 = MenuItemFont::create("PLAY", this, menu_selector(MainMenu::onPlay));
        
        MenuItemFont* item2 = MenuItemFont::create("OPTIONS", this, menu_selector(MainMenu::onOptions));

		MenuItemFont* item3 = MenuItemFont::create("HIGHSCORE", this, menu_selector(MainMenu::onHighScore));

		MenuItemFont* item4 = MenuItemFont::create("SOCIAL", this, menu_selector(MainMenu::onSocial));

		MenuItemFont* item5 = MenuItemFont::create("CREDITS", this, menu_selector(MainMenu::onCredits));
     
        MenuItemFont* exit = MenuItemFont::create("QUIT", this, menu_selector(MainMenu::onExit));
        
        //COMBINE these items to form a menu vertically
        Menu* menu = Menu::create(item1, item2, item3, item4, item5, exit, NULL);
        menu->alignItemsVertically();
        
        this->addChild(menu, 1);
       
        bRet = true;
    } while (0);
    
    return bRet;
}


void MainMenu::onPlay(Object* Sender)
{
    Director::getInstance()->pushScene(SCREEN_GAME->createScene());
}

void MainMenu::onOptions(Object* sender)
{
      SceneManager::sceneMgr()->changeScene(1);
}

void MainMenu::onHighScore(Object* sender)
{
    SceneManager::sceneMgr()->changeScene(2);
}

void MainMenu::onSocial(Object* sender)
{
    SceneManager::sceneMgr()->changeScene(3);
}

void MainMenu::onCredits(Object* sender)
{
    SceneManager::sceneMgr()->changeScene(4);
}

void MainMenu::onExit(Object* sender)
{
    Director::sharedDirector()->end();
}
