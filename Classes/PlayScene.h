#ifndef __PlayScene_SCENE_H__
#define __PlayScene_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

using namespace cocos2d;


class PlayScene : public cocos2d::Layer, public b2ContactListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene);
    
    bool onTouchBegan(Touch *pTouch, Event *pEvent);
    void onTouchMoved(Touch *pTouch, Event *pEvent);
    void onTouchEnded(Touch *pTouch, Event *pEvent);
    
    // 衝突が始まった時に実行
    bool onContactBegin(PhysicsContact& contact);
    
    void applayForceFromBomb(Vec2 bombPosition);
 
    void fireBombEffect(Vec2 bombPosition);
    
    void explosionEnemy(Sprite* enemy);
    
    void setListenner();
    
    void setCornerWall();
    
    void changeGageParamata();
    
    void shotEnemyBullet(float dt);
    
private:
    PhysicsWorld *_world;
    Sprite *charactor;
    
    Vector<Sprite*> spriteVector;
    
    bool isFristTouch;
    
    int enemyHp;
    
    Size visibleSize;
    
    ClippingNode *cNode;
    
    Sprite *enemy;
};

#endif // __PlayScene_SCENE_H__
