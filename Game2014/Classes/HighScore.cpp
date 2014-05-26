/* --------------------------------------------------------------------------------

				Options.h

				Game2014

				Made by Z-Plane May 2014

---------------------------------------------------------------------------------*/

#include "HighScore.h"
#include "MainMenu.h"

Scene* HighScore::createScene()
{
	Scene *scene = NULL;

	do
	{

		scene = Scene::create(); //create the scene
        CC_BREAK_IF(!scene); //if there is no scene, break
        
        HighScore *layer = HighScore::create(); //create a layer
        CC_BREAK_IF(!layer);
        
        //add layer to the scene
        scene->addChild(layer);

	} while (0);

	return scene;
}

bool HighScore::init()
{

	bool ReturnThis = 0;

	do 
	{

		CC_BREAK_IF(!Layer::init());
        
        //enable touch again
        this->setTouchEnabled(true);
        
        //Option Menu items
        
        MenuItemFont* item9 = MenuItemFont::create("BACK", this, menu_selector(HighScore::onExit));
        
        //COMBINE these items to form a menu 
        Menu* menu = Menu::create(item9, NULL);

		//Menu Alignment
        menu->alignItemsVertically();
        
        this->addChild(menu, 1);
        
		ReturnThis = true;
        
	} while (0);
	
	return ReturnThis;

}


void HighScore::onExit(Object* sender)
{
	Director::getInstance()->replaceScene(TransitionSlideInL::create(0.9f, MainMenu::createScene()));
}
