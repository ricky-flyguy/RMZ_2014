#include "HelloWorldScene.h"
#include "SceneManager.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1

Scene* HelloWorld::createScene()
{
    Scene *scene = NULL;
    // 'scene' is an autorelease object
    scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setSpeed(1.5f);
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	layer->setPhyWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

	// To get current scene
	//Director::getInstance()->getRunningScene();

    // return the scene
    return scene;
}
/*
Scene* HelloWorld::getCurrentScene()
{
    if(scene != NULL)
    return scene;
}

*/

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
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

	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5);
	auto node = Node::create();
	node->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
	node->setPhysicsBody(body);
	this->addChild(node);


	Point tempPos = ccp(visibleSize.width/2, (visibleSize.height - visibleSize.height/4));

	//player = Player::create("sky_diver.png", &tempPos);
	tempPos = ccp(visibleSize.width/3, visibleSize.height/3);
	balloon = new Balloon();
	tempPos = ccp(visibleSize.width / 2, visibleSize.height - (visibleSize.height / 4));

	touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);

	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	player = Player::create("sky_diver.png", &tempPos); 

	//tempPos = ccp(50, visibleSize.height/6);
	//civCivilian = Civilian::create("sky_diver.png", 20, &tempPos);

	tempPos = ccp(visibleSize.width/2, visibleSize.height/2);
    bg = Background::create("sky.png", &tempPos);
    
	Sprite* apt = Sprite::create("apartment.png");

	tempPos = ccp(visibleSize.width/8, visibleSize.height - visibleSize.height/4);

	pull = PullIndicator::create(&tempPos, player, this);
	tempPos = ccp(visibleSize.width - visibleSize.width/6, visibleSize.height - visibleSize.height/4);

	downBtn = ArrowBtn::create(&tempPos, ArrowBtn::Type::Down, player);
//	tempPos = ccp(downBtn->getPosition().x - downBtn->getBoundingBox().size.width, downBtn->getPosition().y);
	leftBtn = ArrowBtn::create(&tempPos, ArrowBtn::Type::Left, player);
	tempPos = ccp(downBtn->getPosition().x + downBtn->getBoundingBox().size.width, downBtn->getPosition().y);
	rightBtn = ArrowBtn::create(&tempPos, ArrowBtn::Type::Right, player);
	

	DrawNode* c = DrawNode::create();

	for (float i = 0; i < (2 * M_PI); i += 0.3)
	{
		c->drawSegment(pull->getPosition(), Point(pull->getPosition().x + pull->radius * cos(i), pull->getPosition().y +  pull->radius * sin(i)),  pull->radius, Color4F(0.0f, 0.0f, 0.5f, 0.2f));
	}


	apt->setScale(.5f);
	tempPos = ccp(visibleSize.width/2, visibleSize.height/2.5f);
	apt->setPosition(tempPos);

    this->addChild(bg, 0);
	//this->addChild(apt);
	//this->addChild(balloon);
	this->addChild(player, 100);
	this->addChild(c, 75);
	this->addChild(pull, 105);
	this->addChild(pull->arrow, 105);
	this->addChild(downBtn, 100);
	this->addChild(leftBtn, 100);
	this->addChild(rightBtn, 100);
	
	civMaker = new CivFactory();
	//this->addChild(civMaker->newCiv(), 100);
	iTime = 0;
	schedule(schedule_selector(HelloWorld::update));
    
    //Main menu items
    MenuItemFont* back1 = MenuItemFont::create("Back", this, menu_selector(HelloWorld::onBack));
    
    Menu* menu = Menu::create(back1, NULL);
    menu->alignItemsVertically();
    
    this->addChild(menu, 1);

    
    return true;
}

void HelloWorld::update(float dt)
{
	//player->update(dt);
	//civMaker->update(dt);

	iTime += 1;
	switch (iTime / 60)
	{
	case 1:
		this->addChild(civMaker->newCiv(), 100);
		iTime = 0;
		break;
	case 2:
		//this->addChild(civMaker->newCiv(), 100);
		break;
	case 3:
		//iTime = 0;
		break;
	}

	//CCLog("Pull Pos: (%f, %f)", pull->getPosition().x, pull->getPosition().y);
    
    
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* evt)
{
	if (leftBtn->onTouchBegan(touch, evt)) return true;
	if (rightBtn->onTouchBegan(touch, evt)) return true;
	if (downBtn->onTouchBegan(touch, evt)) return true;

	pull->onTouchBegan(touch, evt);
	return true;
}
void HelloWorld::onTouchMoved(Touch* touch, Event* evt)
{
	leftBtn->onTouchMoved(touch, evt);
	rightBtn->onTouchMoved(touch, evt);
	downBtn->onTouchMoved(touch, evt);
	pull->onTouchMoved(touch, evt);
}
void HelloWorld::onTouchEnded(Touch* touch, Event* evt)
{
	leftBtn->onTouchEnded(touch, evt);
	rightBtn->onTouchEnded(touch, evt);
	downBtn->onTouchEnded(touch, evt);
	Point* poi = new Point(player->getPosition().x, player->getPosition().y);
	Balloon* b = Balloon::createWithForce(poi, pull->onTouchEnded(touch, evt));
	//b->setCivilian(this->civCivilian);

	this->addChild(b, 100);
}


void HelloWorld::addBalloon(Point pos, Point* force)
{
	//Balloon* b = Balloon::createWithForce(&pos, force);
	//Balloon* b = new Balloon();

	//Director::getInstance()->getRunningScene()->addChild(b, 100);
}

void HelloWorld::removeBalloon(Balloon* balloon)
{
	//Director::getInstance()->getRunningScene()->removeChild(balloon, true);
	balloon->removeFromParentAndCleanup(true);
	//balloon->release();
	//balloon = NULL;
}

void HelloWorld::onBack(Object* Sender)
{
   // SceneManager::sceneMgr()->changeScene(0);
    
    Director::getInstance()->popScene();
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
