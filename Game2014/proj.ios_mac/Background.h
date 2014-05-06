//
//  Background.h
//  Game2014
//
//  Created by The Matrix on 2014-05-04.
//
//

#ifndef __Game2014__Background__
#define __Game2014__Background__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class Background : public Sprite
{
private:
    Size size;
    
    
public:
    static Background* create(const std::string &filename, Point* pos);
    bool init();
    
    Background(void);
    ~Background(void);
    
};

#endif /* defined(__Game2014__Background__) */
