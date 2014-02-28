//
//  MainSceneWithAccelector.cpp
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#include "MainSceneWithAccelector.h"
USING_NS_CC;

Scene* MainSceneWithAccelector::scene()
{
    Scene* scene = NULL;
    do
    {
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        MainSceneWithAccelector* layer = MainSceneWithAccelector::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool MainSceneWithAccelector::init()
{
    if (!MainScene::init())
        return false;
    this->schedule(schedule_selector(MainSceneWithAccelector::updateGame));
    this->setAccelerometerEnabled(true);
    return true;
}

void MainSceneWithAccelector::onAccelerate(Acceleration *pAccelerationValue)
{
    getRabbit()->setSpeedX(pAccelerationValue->x * 0.5);
}