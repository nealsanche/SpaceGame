#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    _batchNode = CCSpriteBatchNode::create("Sprites.pvr.ccz");
    this->addChild(_batchNode);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Sprites.plist");
    
    _ship = CCSprite::createWithSpriteFrameName("SpaceFlier_sm_1.png");
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    _ship->setPosition(ccp(winSize.width * 0.1, winSize.height * 0.5));
    _batchNode->addChild(_ship, 1);
    
    // 1) Create the CCParallaxNode
    _backgroundNode = CCParallaxScrollNode::create(); //1
    this->addChild(_backgroundNode,-1);
    
    // 2) Create the sprites will be added to the CCParallaxNode
    _spacedust1 = Sprite::create("bg_front_spacedust.png");
    _spacedust2 = Sprite::create("bg_front_spacedust.png");
    _spacedust3 = Sprite::create("bg_front_spacedust.png");
    _spacedust4 = Sprite::create("bg_front_spacedust.png");
    _planetsunrise = Sprite::create("bg_planetsunrise.png");
    _planetsunrise2 = Sprite::create("bg_planetsunrise.png");
    _galaxy = Sprite::create("bg_galaxy.png");
    _galaxy2 = Sprite::create("bg_galaxy.png");
    _spacialanomaly = Sprite::create("bg_spacialanomaly.png");
    _spacialanomaly2 = Sprite::create("bg_spacialanomaly2.png");

    _spacialanomaly3 = Sprite::create("bg_spacialanomaly.png");
    _spacialanomaly4 = Sprite::create("bg_spacialanomaly2.png");

    // 3) Determine relative movement speeds for space dust and background
    Point dustSpeed = ccp(0.1, 0.1);
    Point bgSpeed = ccp(0.05, 0.05);
    
    // 4) Add children to CCParallaxNode
    
    _backgroundNode->addInfiniteScrollXWithZ(0, dustSpeed, ccp(0,0), _spacedust1, _spacedust2, NULL);
    
    _backgroundNode->addInfiniteScrollXWithZ(0, dustSpeed, ccp(-1 * _spacedust1->getContentSize().width/2,0), _spacedust3, _spacedust4, NULL);

    _backgroundNode->addInfiniteScrollXWithZ(-1, bgSpeed, ccp(0, winSize.height * 0.7), _galaxy, _galaxy2, NULL);
    _backgroundNode->addInfiniteScrollXWithZ(-1 , bgSpeed, ccp(600, winSize.height * 0), _planetsunrise, _planetsunrise2, NULL);
    _backgroundNode->addInfiniteScrollXWithZ(-1, bgSpeed, ccp(900, winSize.height * 0.3), _spacialanomaly, _spacialanomaly3, NULL);
    _backgroundNode->addInfiniteScrollXWithZ(-1, bgSpeed, ccp(1500, winSize.height * 0.9), _spacialanomaly2, _spacialanomaly4, NULL);
    
    this->scheduleUpdate();
    
    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::update(float dt) {
    
    _backgroundNode->updateWithVelocity(ccp(-100,0), dt);
    /*
    CCPoint backgroundScrollVert = ccp(-1000, 0);
    _backgroundNode->setPosition(ccpAdd(_backgroundNode->getPosition(), ccpMult(backgroundScrollVert, dt)));

     CCArray *spaceDusts = CCArray::createWithCapacity(2);
    spaceDusts->addObject(_spacedust1);
    spaceDusts->addObject(_spacedust2);
    for ( int ii = 0; ii <spaceDusts->count(); ii++ ) {
        CCSprite * spaceDust = (CCSprite *)(spaceDusts->objectAtIndex(ii));
        float xPosition = _backgroundNode->convertToWorldSpace(spaceDust->getPosition()).x;
        float size = spaceDust->getContentSize().width;
        if ( xPosition < -size/2 ) {
            _backgroundNode->incrementOffset(ccp(spaceDust->getContentSize().width*2,0),spaceDust);
        }
    }
    
    CCArray *backGrounds = CCArray::createWithCapacity(4);
    backGrounds->addObject(_galaxy);
    backGrounds->addObject(_planetsunrise);
    backGrounds->addObject(_spacialanomaly);
    backGrounds->addObject(_spacialanomaly2);
    for ( int ii = 0; ii < backGrounds->count(); ii++ ) {
        CCSprite* background = (CCSprite *)(backGrounds->objectAtIndex(ii));
        float xPosition = _backgroundNode->convertToWorldSpace(background->getPosition()).x;
        float size = background->getContentSize().width;
        if ( xPosition < -size ) {
            _backgroundNode->incrementOffset(ccp(2000,0),background);
        }
    }
     */
    
}

