//
//  HelloWorldWithTouch.h
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#ifndef __Test__HelloWorldWithTouch__
#define __Test__HelloWorldWithTouch__

#include <iostream>

#include "cocos2d.h"
#include "HelloWorldScene.h"

class HelloWorldWithTouch: public HelloWorld
{
public:
    virtual bool init();
    
    static cocos2d::Scene* scene();
        
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *pEvent);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorldWithTouch);
};

#endif /* defined(__Test__HelloWorldWithTouch__) */
