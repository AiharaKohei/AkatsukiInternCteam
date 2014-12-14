#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;


class GameScene: public cocos2d::Layer, public b2ContactListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    void onAcceleration(Acceleration* acc, Event* unused_event);
    bool onTouchBegan(Touch *pTouch, Event *pEvent);
    void onTouchMoved(Touch *pTouch, Event *pEvent);
    void onTouchEnded(Touch *pTouch, Event *pEvent);
    
    // 衝突が始まった時に実行
    bool onContactBegin(PhysicsContact& contact);
 
    
private:
    PhysicsWorld *_world;
    Sprite *charactor;
    
    std::vector<Sprite*> spriteVector;
    
    void mycallback(cocos2d:: Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
