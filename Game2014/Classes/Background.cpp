//
//  Background.cpp
//  Game2014
//
//  Created by The Matrix on 2014-05-04.
//
//

#include "Background.h"

Background::Background(void)
{
    size = Director::getInstance()->getVisibleSize();
    this->init();
}

bool Background::init()
{
    return true;
}

Background* Background::create(const std::string &filename, Point* pos)
{
    Background* bg = new Background();
    
    if(bg && bg->initWithFile(filename))
    {
        bg->autorelease();
        bg->setPosition(*pos);
        
        bg->setRotation(90.0f);
        bg->setScale(2.0f);
        
        return bg;
    }
    
    CC_SAFE_DELETE(bg);
    
    return NULL;
}

Background::~Background(void)
{
    
}