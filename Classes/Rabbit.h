//
//  Rabbit.h
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#ifndef __Test__Rabbit__
#define __Test__Rabbit__

#include <iostream>

#include "cocos2d.h"
#include "Utils.h"

class Rabbit: public cocos2d::LabelTTF
{
private:
    double _dSpeedX;
    double _dSpeedY;
public:
    Rabbit();
    
    virtual ~Rabbit();
    
    virtual bool init();
    
    void render();
    
    void setSpeedX(double speed) { _dSpeedX = speed; }
    
    double getSpeedX() { return _dSpeedX; }
    
    double getSpeedY() { return _dSpeedY; }
    
    double getOffsetY();
    
    void jump(double speed=DEFAULT_SPEED) { _dSpeedY = speed; }
    
    bool isInBottom() { return getPosition().y <= getContentSize().height; }
    
    static Rabbit* create(const std::string& string, const std::string& fontName, float fontSize);
    
    static Rabbit* create(const std::string& string, const std::string& fontName, float fontSize,
                          const cocos2d::Size& dimensions, cocos2d::TextHAlignment hAlignment);
    
    static Rabbit* create(const std::string& string, const std::string& fontName, float fontSize,
                          const cocos2d::Size &dimensions, cocos2d::TextHAlignment hAlignment,
                          cocos2d::TextVAlignment vAlignment);
};

#endif /* defined(__Test__Rabbit__) */
