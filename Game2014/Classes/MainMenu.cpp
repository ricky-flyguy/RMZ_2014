//
//  MainMenu.cpp
//  Game2014
//
//  Created by The Matrix on 2014-05-07.
//
//

#include "MainMenu.h"
#include "HelloWorldScene.h"

using namespace cocos2d;


Scene* MainMenu::createScene()
{
    Scene *scene = NULL;
    
    do {
        
       scene = Scene::create(); //create the scene
        CC_BREAK_IF(!scene); //if there is no scene, break
        
        MainMenu *layer = MainMenu::create(); //create a layer
        CC_BREAK_IF(!layer);
        
        //add layer to the scene
        scene->addChild(layer);
        
    } while (0);
    
    return scene;
}

bool MainMenu::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        
        //enable touch
        this->setTouchEnabled(true);
        
        //Main menu items
        MenuItemFont* item1 = MenuItemFont::create("PLAY", this, menu_selector(MainMenu::onPlay));
        
        MenuItemFont* item2 = MenuItemFont::create("HELP", this, menu_selector(MainMenu::onOptions));
        
        MenuItemFont* item3 = MenuItemFont::create("QUIT", this, menu_selector(MainMenu::onExit));
        
        //COMBINE these items to form a menu vertically
        Menu* menu = Menu::create(item1, item2, item3, NULL);
        menu->alignItemsVertically();
        
        this->addChild(menu, 1);
        
        bRet = true;
    } while (0);
    
    return bRet;
}


void MainMenu::onPlay(Object* sender)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.9f, HelloWorld::createScene()));
}

void MainMenu::onOptions(Object* sender)
{
    
}

void MainMenu::onExit(Object* sender)
{
    Director::sharedDirector()->end();
}