#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCParallaxScrollNode.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

USING_NS_CC;

typedef enum {
    KENDREASONWIN,
    KENDREASONLOSE
} EndReason;

class HelloWorld : public Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    float randomValueBetween(float low, float high);
    void setInvisible(CCNode * node);
    float getTimeTick();
    
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
private:
	SpriteBatchNode* _batchNode;
	Sprite* _ship;
    
    float _shipPointsPerSecY;
    
    CCParallaxScrollNode *_backgroundNode;
    Sprite *_spacedust1;
    Sprite *_spacedust2;
    Sprite *_spacedust3;
    Sprite *_spacedust4;
    Sprite *_planetsunrise;
    Sprite *_galaxy;
    Sprite *_spacialanomaly;
    Sprite *_spacialanomaly2;

    Sprite *_planetsunrise2;
    Sprite *_galaxy2;
    Sprite *_spacialanomaly3;
    Sprite *_spacialanomaly4;
    
    CCArray* _asteroids;
    int _nextAsteroid;
    float _nextAsteroidSpawn;
    
    CCArray* _shipLasers;
    int _nextShipLaser;
    
    int _lives;
    
    double _gameOverTime;
    bool _gameOver;

    // scheduled Update
    void update(float dt);
    
    void endScene(EndReason endReason);
    void restartTapped();
};

#endif // __HELLOWORLD_SCENE_H__
