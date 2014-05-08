#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "Balloon.h"
#include "Background.h"
#include "PullIndicator.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:

	Player* player;
	Balloon* balloon;

	LabelTTF* label;
    
    Background* bg;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(); 

	virtual void update(float dt);

	EventListenerTouchOneByOne* touchListener;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
