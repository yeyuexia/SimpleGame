//
//  HelloWorldWithAccelector.cpp
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#include "HelloWorldWithAccelector.h"
USING_NS_CC;

Scene* HelloWorldWithAccelector::scene()
{
    Scene* scene = NULL;
    do
    {
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        HelloWorldWithAccelector* layer = HelloWorldWithAccelector::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool HelloWorldWithAccelector::init()
{
    if (!HelloWorld::init())
        return false;
    this->schedule(schedule_selector(HelloWorldWithAccelector::updateGame));
    this->setAccelerometerEnabled(true);
    return true;
}

void HelloWorldWithAccelector::onAccelerate(Acceleration *pAccelerationValue)
{
    getRabbit()->setSpeedX(pAccelerationValue->x * 0.5);
}