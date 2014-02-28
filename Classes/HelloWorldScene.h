#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ScoreBoard.h"
#include "Rabbit.h"

class HelloWorld : public cocos2d::LayerColor
{
private:
    Rabbit* _pRabbit;
    cocos2d::Vector<cocos2d::Object*> _bells;
    cocos2d::Vector<cocos2d::Object*> _bellPool;
private:
    bool isCollidedBell(const cocos2d::Rect& rect);
    
    double getBellSpeed();
    
    void generateBells();
    
    void deleteBells();
    
    void renderBells();
    
private:
    void renderRabbit();
    
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    HelloWorld();
    
    ~HelloWorld();
    
    virtual bool init();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    Rabbit* getRabbit() { return _pRabbit; }
    
    // a selector callback
    void menuCloseCallback(cocos2d::Object* pSender);
    
    void startGameCallback(cocos2d::Object* pSender);
    
    void updateGame(float dt);
    
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* pEvent);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
