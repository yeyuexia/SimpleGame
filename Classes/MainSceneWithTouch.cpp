//
//  MainSceneWithTouch.cpp
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#include "MainSceneWithTouch.h"
USING_NS_CC;

Scene* MainSceneWithTouch::scene()
{
    Scene* scene = NULL;
    do
    {
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        MainSceneWithTouch* layer = MainSceneWithTouch::create();
        CC_BREAK_IF(!layer);
        CCLOG("create  MainSceneWithTouch");
        scene->addChild(layer);
    } while (0);
    return scene;
}

bool MainSceneWithTouch::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF(!MainScene::init());
        this->schedule(schedule_selector(MainSceneWithTouch::updateGame));
        bRet = true;
    } while (0);
    return bRet;
}

void MainSceneWithTouch::onTouchesMoved(const std::vector<Touch*>& touches, Event *pEvent)
{
    Touch* pTouch = touches[0];
    Point deltaPoint = pTouch->getDelta();
    CCLOG("%f", deltaPoint.x);
    getRabbit()->setSpeedX(deltaPoint.x);
}