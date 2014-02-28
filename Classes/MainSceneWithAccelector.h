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

#include "MainScene.h"

class MainSceneWithAccelector: public MainScene
{
public:
    virtual bool init();
    
    static cocos2d::Scene* scene();
    
    void onAccelerate(cocos2d::Acceleration *pAccelerationValue);
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainSceneWithAccelector);
};

#endif /* defined(__Test__HelloWorldWithAccelector__) */
