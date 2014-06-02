/* --------------------------------------------------------------------------------

				Options.cpp

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#include "Options.h"
#include "MainMenu.h"
#include "Audio.h"
#include "SceneManager.h"

Scene* Options::createScene()
{
	Scene *scene = NULL;

	do
	{

		scene = Scene::create(); //create the scene
        CC_BREAK_IF(!scene); //if there is no scene, break
        
        Options *layer = Options::create(); //create a layer
        CC_BREAK_IF(!layer);
        
        //add layer to the scene
        scene->addChild(layer);

	} while (0);

	return scene;
}

bool Options::init()
{

	bool ReturnThis = 0;

	do 
	{

		CC_BREAK_IF(!Layer::init());
        
        //enable touch again
        this->setTouchEnabled(true);
        
        //Option Menu items
		MenuItemFont* item1 = MenuItemFont::create("AUDIO", this, menu_selector(Options::onAudio));
        
        MenuItemFont* item2 = MenuItemFont::create("RMZLINKTOGAMESANDSHEIT", this, menu_selector(Options::onRMZLINK));
        
        MenuItemFont* exit = MenuItemFont::create("BACK", this, menu_selector(Options::onExit));
        
        //COMBINE these items to form a menu 
        Menu* menu = Menu::create(item1, item2, exit, NULL);

		//Menu Alignment
        menu->alignItemsVertically();
        
        this->addChild(menu, 1);
        
		ReturnThis = true;
        
	} while (0);
	
	return ReturnThis;

}

void Options::onAudio(Object* sender)
{
    SceneManager::sceneMgr()->changeScene(0);
}

void Options::onRMZLINK(Object* sender)
{
    
}

void Options::onExit(Object* sender)
{
    SceneManager::sceneMgr()->changeScene(0);
}

