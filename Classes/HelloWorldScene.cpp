#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

HelloWorld::HelloWorld()
: _pRabbit(NULL)
{
}

HelloWorld::~HelloWorld()
{
    if (_pRabbit)
    {
        delete _pRabbit;
        _pRabbit = NULL;
    }
    
}

Scene* HelloWorld::scene() {
    // 'scene' is an autorelease object
    Scene* scene = NULL;
    do {
        scene = Scene::create();
        CC_BREAK_IF(!scene);
        HelloWorld* layer = HelloWorld::create();
        CC_BREAK_IF(!layer);
        scene->addChild(layer);
    } while (0);
    CCLOG("create  HelloWorld");
    // 'layer' is an autorelease object
//    HelloWorld *layer = HelloWorld::create();
//
//    // add layer as a child to scene
//    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    bool bRet = false;
    do {
        CC_BREAK_IF(!LayerColor::initWithColor( Color4B(0, 0, 0, 0)));
        _pRabbit = Rabbit::create("Rabbit", "Arial", 24);
        _pRabbit->setPosition(Point(Director::getInstance()->getVisibleOrigin().x + Director::getInstance()->getVisibleSize().width/2,
                                    Director::getInstance()->getVisibleOrigin().y + _pRabbit->getContentSize().height));
        addChild(_pRabbit);
        ScoreBoard::init();
        setTouchEnabled(true);
//        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("pew-pew-lei.wav");
        bRet = true;
    } while (0);
    return bRet;
}

void HelloWorld::updateGame(float dt)
{
    renderRabbit();
    renderBells();
//    CCLOG("height:%d", ScoreBoard::getHeight());
}

void HelloWorld::renderRabbit()
{
    Point position = _pRabbit->getPosition();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    position.x = position.x + _pRabbit->getSpeedX();
    if (position.x > visibleSize.width - _pRabbit->getContentSize().width) {
        position.x = visibleSize.width - _pRabbit->getContentSize().width;
    } else if (position.x < 0){
        position.x = 0;
    }
    _pRabbit->setSpeedX(0);
    
    double offsetY = _pRabbit->getOffsetY();
    position.y = position.y + offsetY;
    CCLOG("rabbit position:%f, height:%f", position.y, _pRabbit->getContentSize().height);
    double middleOfScreen = visibleSize.height * 0.5;
    if (position.y >= middleOfScreen || (position.y < middleOfScreen && ScoreBoard::getHeight() > middleOfScreen)) {
        position.y = middleOfScreen;
    }
    ScoreBoard::updateHeight(offsetY);
    if (position.y <= _pRabbit->getContentSize().height)
    {
        position.y = _pRabbit->getContentSize().height;
        ScoreBoard::clearData();
    }
    _pRabbit->setPosition(position);
    Rect rabbitRect = Rect(position.x, position.y, _pRabbit->getContentSize().width, _pRabbit->getContentSize().height);
    if (isCollidedBell(rabbitRect)) {
        int speedY = int(_pRabbit->getSpeedY());
        if (speedY > 0) {
            _pRabbit->jump((speedY>>1) + DEFAULT_SPEED);
        } else {
            _pRabbit->jump();
        }
    }
}

void HelloWorld::menuCloseCallback(Object* pSender)
{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
//	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//#else
//    CCDirector::sharedDirector()->end();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//#endif
    Director::getInstance()->end();
}

void HelloWorld::startGameCallback(Object* pSender)
{
    
}

void HelloWorld::onTouchesEnded(const std::vector<Touch*>& touches, cocos2d::Event* pEvent) {
    CCLOG("jump");
    if (_pRabbit->isInBottom())
    {
        this->_pRabbit->jump();
    }
}


//////////////////////////////////////// bell //////////////////////////////////////////////
void HelloWorld::renderBells()
{
    double speed = getBellSpeed();
    double time = Director::getInstance()->getSecondsPerFrame();
    for( auto it : _bells) {
        LabelTTF* bell = dynamic_cast<LabelTTF*>(it);
        bell->setPosition(Point(bell->getPositionX(), bell->getPositionY() + speed*time));
    }
    
    generateBells();
    deleteBells();
}

double HelloWorld::getBellSpeed()
{
    double middleOfScreen = Director::getInstance()->getVisibleSize().height * 0.5;
    //    CCLOG("height:%d, visible height:%d", ScoreBoard::getHeight(), int(_visibleSize.height) >> 1);
    if (ScoreBoard::getHeight() > middleOfScreen) {
        return BELL_SPEED - _pRabbit->getSpeedY();
    } else {
        return BELL_SPEED;
    }
}

void HelloWorld::generateBells()
{
    LabelTTF* bell = NULL;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    if (_bells.size() > 0) {
        bell = dynamic_cast<LabelTTF*>(_bells.back());
        if (visibleSize.height - bell->getPositionY() <= BELLS_STRIDE) {
            return;
        }
    }
    int count = rand() % 4;
    int i;
    //    CCLOG("base bell height:%f", _pBaseBell->getContentSize().height);
    //    float initHeight = _origin.x +_visibleSize.height + _pBaseBell->getContentSize().height;
    for (i=0; i<count; ++i)
    {
        bool usingPool = false;
        if (_bellPool.size() > 0) {
            bell = dynamic_cast<LabelTTF*>(_bellPool.back());
            //            CCLOG("enter pool, pool count:%zd", _bellPool.size());
            usingPool = true;
        }
        else
        {
            //            CCLOG("new bell, total count:%zd", _bells.size());
            bell = CCLabelTTF::create("Bell", "Arial", 20);
        }
        float initHeight = origin.x +visibleSize.height + bell->getContentSize().height;
        bell->setPosition(Point(origin.x + rand() % int(visibleSize.width - bell->getContentSize().width), initHeight));
//        CCLOG("bell position:%f, %f", bell->getPositionX(), bell->getPositionY());
        _bells.pushBack(bell);
        addChild(bell);
        if (usingPool) {
            _bellPool.eraseObject(bell);
        }
    }
}

void HelloWorld::deleteBells()
{
    LabelTTF* bell = NULL;
    Vector<Object*> prepareEarseBells;
    float screenHeight = Director::getInstance()->getVisibleSize().height;
    for (auto it : _bells)
    {
        bell = dynamic_cast<LabelTTF*>(it);
        if (bell->getPositionY() < -screenHeight ||
            bell->getPositionY() > 2 * screenHeight + bell->getContentSize().height ||
            (bell->getPositionY() < 0.5 * screenHeight - ScoreBoard::getHeight()))
        {
            //            CCLOG("object:%s, retain count:%d", bell, bell->getReferenceCount());
            prepareEarseBells.pushBack(bell);
            //            CCLOG("object:%s, retain count:%d", bell, bell->getReferenceCount());
        }
    }
    for (auto it : prepareEarseBells)
    {
        bell = dynamic_cast<LabelTTF*>(it);
        //        CCLOG("_bellPool object:%s, retain count:%d", bell, bell->getReferenceCount());
        _bells.eraseObject(bell);
        _bellPool.pushBack(bell);
        removeChild(bell, true);
    }
}

bool HelloWorld::isCollidedBell(const cocos2d::Rect &rect) {
    Object* prepareEarseBell = NULL;
    for (auto it : _bells) {
        auto bell = dynamic_cast<LabelTTF*>(it);
        Rect bellRect = Rect(bell->getPositionX(),
                             bell->getPositionY(),
                             bell->getContentSize().width,
                             bell->getContentSize().height);
        if (rect.intersectsRect(bellRect)) {
            prepareEarseBell = bell;
        }
    }
    if (prepareEarseBell) {
        //        CCLOG("_bellPool object:%s, retain count:%d", bell, bell->getReferenceCount());
        auto bell = dynamic_cast<LabelTTF*>(prepareEarseBell);
        _bells.eraseObject(bell);
        _bellPool.pushBack(bell);
        removeChild(bell, true);
        return true;
    } else {
        return false;
    }
}

