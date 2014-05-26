/* --------------------------------------------------------------------------------

				Social.cpp

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#include "Social.h"
#include "MainMenu.h"

Scene* Social::createScene()
{
	Scene *scene = NULL;

	do
	{

		scene = Scene::create(); //create the scene
        CC_BREAK_IF(!scene); //if there is no scene, break
        
		Social *layer = Social::create(); //create a layer
        CC_BREAK_IF(!layer);
        
        //add layer to the scene
        scene->addChild(layer);

	} while (0);

	return scene;
}

bool Social::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        
        //enable touch
        this->setTouchEnabled(true);
        
        //Credits list
        
        MenuItemFont* exit = MenuItemFont::create("BACK", this, menu_selector(Social::onExit));
        
        //COMBINE these items to form a menu vertically
        Menu* menu = Menu::create(exit, NULL);
        menu->alignItemsVertically();
        
        this->addChild(menu, 1);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void Social::onExit(Object* sender)
{
	Director::getInstance()->replaceScene(TransitionSlideInL::create(0.9f, MainMenu::createScene()));
}