#include "HelloWorldScene.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
	//closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

 //   // create menu, it's an autorelease object
 //   auto menu = Menu::create(closeItem, NULL);
 //   menu->setPosition(Point::ZERO);
 //   this->addChild(menu, 1);

 //   /////////////////////////////
 //   // 3. add your codes below...

 //   // add a label shows "Hello World"
 //   // create and initialize a label
 //   
    label = LabelTTF::create("Hello World", "Arial", 24);
 //   
 //   // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

 //   // add the label as a child to this layer
    this->addChild(label, 1);

 //   // add "HelloWorld" splash screen"
 //   auto sprite = Sprite::create("HelloWorld.png");

 //   // position the sprite on the center of the screen
 //   sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

 //   // add the sprite as a child to this layer
 //   this->addChild(sprite, 0);

	Point tempPos = ccp(visibleSize.width/2, (visibleSize.height - visibleSize.height/4));

	player = Player::create("sky_diver.png", &tempPos);
	tempPos = ccp(visibleSize.width/3, visibleSize.height/3);
	balloon = Balloon::create("balloon.png", &tempPos);

	touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = [&](Touch* touch, Event* evt) // Explination: http://tinyurl.com/mu69n35
	{
		EventTouch* e = (EventTouch*)evt;

		Point loc = e->getCurrentTarget()->convertToNodeSpace(touch->getLocation());

		//Balloon *b = Balloon::create("balloon.png", &loc);

		//this->addChild(b);
		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	player = Player::create("sky_diver.png", &tempPos); 
	tempPos = ccp(visibleSize.width/2, visibleSize.height/2);
    bg = Background::create("sky.png", &tempPos);
    
    bg->setRotation(90.0f);    
    bg->setScale(2.0f);

	Sprite* apt = Sprite::create("apartment.png");


	tempPos = ccp(visibleSize.width/2, visibleSize.height/2);

	PullIndicator* pull = PullIndicator::create(&tempPos);

	DrawNode* c = DrawNode::create();

	for (float i = 0; i < (2 * M_PI); i += 0.3)
	{
		c->drawSegment(pull->getPosition(), Point(pull->getPosition().x + pull->radius * cos(i), pull->getPosition().y +  pull->radius * sin(i)),  pull->radius, Color4F(0.0f, 0.0f, 0.5f, 1.0f));
	}


	apt->setScale(.5f);
	tempPos = ccp(visibleSize.width/2, visibleSize.height/2.5f);
	apt->setPosition(tempPos);

    this->addChild(bg);
	//this->addChild(apt);
	this->addChild(balloon);
	this->addChild(player);
	this->addChild(c);
	this->addChild(pull);

	schedule(schedule_selector(HelloWorld::update));
    
    return true;
}

void HelloWorld::update(float dt)
{
	player->update(dt);
	CCLog("hi");
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
