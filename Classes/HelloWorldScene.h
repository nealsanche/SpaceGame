#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCParallaxScrollNode.h"

USING_NS_CC;

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
    
private:
	SpriteBatchNode* _batchNode;
	Sprite* _ship;
    
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

    // scheduled Update
    void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
