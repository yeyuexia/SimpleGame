//
//  Rabbit.cpp
//  Test
//
//  Created by yeyuexia on 2/16/14.
//
//

#include "Rabbit.h"
#include "HelloWorldScene.h"
#include "ScoreBoard.h"

USING_NS_CC;

Rabbit::Rabbit()
: _dSpeedX(0.0)
, _dSpeedY(0.0)
{
}

bool Rabbit::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF(!LabelTTF::init());
        
        bRet = true;
    } while (0);
    return bRet;
}


Rabbit::~Rabbit()
{
}

Rabbit* Rabbit::create(const std::string& string, const std::string& fontName, float fontSize)
{
    return Rabbit::create(string, fontName, fontSize,
                            Size::ZERO, TextHAlignment::CENTER, TextVAlignment::TOP);
}

Rabbit * Rabbit::create(const std::string& string, const std::string& fontName, float fontSize,
                            const Size& dimensions, TextHAlignment hAlignment)
{
    return Rabbit::create(string, fontName, fontSize, dimensions, hAlignment, TextVAlignment::TOP);
}

Rabbit* Rabbit::create(const std::string& string, const std::string& fontName, float fontSize,
                           const Size &dimensions, TextHAlignment hAlignment,
                           TextVAlignment vAlignment)
{
    Rabbit *ret = new Rabbit();
    if(ret && ret->initWithString(string, fontName, fontSize, dimensions, hAlignment, vAlignment))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

double Rabbit::getOffsetY()
{
    double time = Director::getInstance()->getSecondsPerFrame();
    double preSpeed = _dSpeedY;
    if (!isInBottom())
    {
        _dSpeedY += GRAVITY * time;
    }
    else if (_dSpeedY < 0)
    {
        _dSpeedY = 0;
    }
    return preSpeed * time + 0.5 * GRAVITY * time * time;
}