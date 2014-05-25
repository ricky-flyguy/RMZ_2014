#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "Balloon.h"
#include "Background.h"
#include "PullIndicator.h"
#include "MainMenu.h"
//#include "Civilian.h"
#include "RMZHelper.h"
#include "CivFactory.h"
#include "ArrowBtn.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
private:
	PhysicsWorld* m_World;
	EventListenerTouchOneByOne* touchListener;

	int iTime;

public:

	Player* player;
	Balloon* balloon;
	PullIndicator* pull;
	//Civilian* civCivilian;
	CivFactory* civMaker;
	Size visibleSize;
	ArrowBtn* leftBtn, *rightBtn, *downBtn;

	LabelTTF* label;

	CCArray* balloons;
    
    Background* bg;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	void addBalloon(Point pos, Point* force);
	static void removeBalloon(Balloon* balloon);

	void setPhyWorld(PhysicsWorld* world) { m_World = world; }
	PhysicsWorld* getPhysicsWorld() { return m_World; }

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(); 

	virtual void update(float dt);

	bool onTouchBegan(Touch* touch, Event* evt);
	void onTouchMoved(Touch* touch, Event* evt);
	void onTouchEnded(Touch* touch, Event* evt);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
