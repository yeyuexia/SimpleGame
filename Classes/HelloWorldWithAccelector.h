//
//  HelloWorldWithAccelector.h
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#ifndef __Test__HelloWorldWithAccelector__
#define __Test__HelloWorldWithAccelector__

#include <iostream>

#include "HelloWorldScene.h"

class HelloWorldWithAccelector: public HelloWorld
{
public:
    virtual bool init();
    
    static cocos2d::Scene* scene();
    
    void onAccelerate(cocos2d::Acceleration *pAccelerationValue);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorldWithAccelector);
};

#endif /* defined(__Test__HelloWorldWithAccelector__) */
