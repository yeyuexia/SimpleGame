//
//  HelloWorldWithTouch.cpp
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#include "HelloWorldWithTouch.h"
USING_NS_CC;

Scene* HelloWorldWithTouch::scene()
{
    Scene* scene = NULL;
    do
    {
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        HelloWorldWithTouch* layer = HelloWorldWithTouch::create();
        CC_BREAK_IF(!layer);
        CCLOG("create  HelloWorldWithTouch");
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool HelloWorldWithTouch::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF(!HelloWorld::init());
        this->schedule(schedule_selector(HelloWorldWithTouch::updateGame));
        bRet = true;
    } while (0);
    return bRet;
}

void HelloWorldWithTouch::onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent)
{
    Touch* pTouch = touches[0];
    Point deltaPoint = pTouch->getDelta();
    CCLOG("%f", deltaPoint.x);
    getRabbit()->setSpeedX(deltaPoint.x);
}