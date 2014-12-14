#include "StageScene.h"
#include "GameScene.h"


USING_NS_CC;
#define TAG_CHARA 0
#define TAG_ENEMY 4

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
  
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);
    

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    spriteVector.clear();
    
    
    Device::setAccelerometerEnabled(true);
    auto accelerationListener = EventListenerAcceleration::create(CC_CALLBACK_2(GameScene::onAcceleration, this));
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(accelerationListener, this);
 
    Director::getInstance()->getEventDispatcher()->setEnabled(true);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    auto p_listener = EventListenerPhysicsContact::create();
    p_listener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(p_listener, this);
    
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.restitution = 1.0f;
    material.friction = 0.0f;
    
    for (int i = 0; i < 80; i++) {
        int randX = rand() % 100;
        int randY = rand() % 100;
        
        Sprite *chara = Sprite::create("CloseSelected.png");
        chara->setScale(0.6);
        chara->setPosition(Point(visibleSize.width/2 * (randX / 100.0 + 0.5), visibleSize.height/4 * randY / 100.0));
        PhysicsBody *pBody = PhysicsBody::createCircle(10);
        pBody->setContactTestBitmask(2);
        chara->setTag(TAG_CHARA);
        chara->setPhysicsBody(pBody);
        this->addChild(chara);
        spriteVector.push_back(chara);
    }
    
    for (int i = 0; i < 80; i++) {
        int randX = rand() % 100;
        int randY = rand() % 100;
        
        Sprite *enemy = Sprite::create("enemy.png");
        enemy->setScale(0.6);
        enemy->setPosition(Point(visibleSize.width/2 * (randX / 100.0 + 0.5), visibleSize.height - visibleSize.height/4 * randY / 100.0));
        PhysicsBody *pBody = PhysicsBody::createCircle(10);
        pBody->setContactTestBitmask(1);
        enemy->setTag(TAG_ENEMY);
        enemy->setPhysicsBody(pBody);
        this->addChild(enemy);
    }
    
    
    auto wallBottom = Sprite::create();
    wallBottom->setPosition(visibleSize.width/2, 0);
    wallBottom->setTextureRect(Rect(0,0,visibleSize.width,10));
    wallBottom->setColor(Color3B(255,255,255));
    
    auto pWallBottom = PhysicsBody::createBox(wallBottom->getContentSize(), material);
    pWallBottom->setDynamic(false);
    pWallBottom->setRotationEnable(false);
    wallBottom->setPhysicsBody(pWallBottom);
    addChild(wallBottom);
    
    

    auto wallTop = Sprite::create();
    wallTop->setPosition(visibleSize.width/2, visibleSize.height);
    wallTop->setTextureRect(Rect(0,0,visibleSize.width,10));
    wallTop->setColor(Color3B(255,255,255));

    auto pWallTop = PhysicsBody::createBox(wallTop->getContentSize(), material);
    pWallTop->setDynamic(false);
    pWallTop->setRotationEnable(false);
    wallTop->setPhysicsBody(pWallTop);
    addChild(wallTop);
    
    
    auto wallLeft = Sprite::create();
    wallLeft->setPosition(0, visibleSize.height/2);
    wallLeft->setTextureRect(Rect(0,0,10,visibleSize.height));
    wallLeft->setColor(Color3B(255,255,255));
    
    auto pWallLeft = PhysicsBody::createBox(wallLeft->getContentSize(), material);
    pWallLeft->setDynamic(false);
    pWallLeft->setRotationEnable(false);
    wallLeft->setPhysicsBody(pWallLeft);
    addChild(wallLeft);
    
    auto wallRight = Sprite::create();
    wallRight->setPosition(visibleSize.width, visibleSize.height/2);
    wallRight->setTextureRect(Rect(0,0,10,visibleSize.height));
    wallRight->setColor(Color3B(255,255,255));
    
    auto pWallRight = PhysicsBody::createBox(wallRight->getContentSize(), material);
    pWallRight->setDynamic(false);
    pWallRight->setRotationEnable(false);
    wallRight->setPhysicsBody(pWallRight);
    addChild(wallRight);
    
    
    auto wall1 = Sprite::create();
    wall1->setPosition(visibleSize.width/2 - 100, visibleSize.height/2 + 200);
    wall1->setTextureRect(Rect(0, 0, 150, 10));
    wall1->setColor(Color3B(255,255,255));
    
    auto pWall1 = PhysicsBody::createBox(wall1->getContentSize(), material);
    pWall1->setDynamic(false);
    pWall1->setRotationEnable(false);
    wall1->setPhysicsBody(pWall1);
    addChild(wall1);
    
    auto wall2 = Sprite::create();
    wall2->setPosition(visibleSize.width/2 + 100, visibleSize.height/2 - 200);
    wall2->setTextureRect(Rect(0, 0, 150, 10));
    wall2->setColor(Color3B(255,255,255));
    
    auto pWall2 = PhysicsBody::createBox(wall2->getContentSize(), material);
    pWall2->setDynamic(false);
    pWall2->setRotationEnable(false);
    wall2->setPhysicsBody(pWall2);
    addChild(wall2);
    
    return true;
}

void GameScene::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *unused_event){
}

bool GameScene::onTouchBegan(Touch *pTouch, Event *pEvent){
    Vector<Sprite*>::iterator the_iterator = spriteVector.begin();
    while(the_iterator != spriteVector.end()) {

        Sprite *chara  = *the_iterator;
        Vec2 forceVec2 = Vec2(chara->getPosition() - pTouch->getLocation());
        float vecLength = 100000 / sqrtf(forceVec2.x * forceVec2.x + forceVec2.y * forceVec2.y);
        if(vecLength > 700)
            vecLength = 1000;
        Vec2 forceVec2Normal = forceVec2.getNormalized();
        
        chara->getPhysicsBody()->setVelocity(vecLength * forceVec2Normal);

        the_iterator++;
    }

    return true;
}

void GameScene::onTouchMoved(Touch *pTouch, Event *pEvent){
    
}

void GameScene::onTouchEnded(Touch *pTouch, Event *pEvent){
    
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact){
    Sprite *itemA = dynamic_cast<Sprite*>(contact.getShapeA()->getBody()->getNode());
    if (itemA) {
        log("itemA %d", itemA->getTag());
    }
    Sprite *itemB = dynamic_cast<Sprite*>(contact.getShapeB()->getBody()->getNode());
    if (itemB) {
        log("itemB %d", itemB->getTag());
    }
    if (itemA->getTag() != itemB->getTag()) {
        log("消えよ！");

        if (itemA->getTag() == TAG_ENEMY)
            this->removeChild(itemA);
        if (itemB->getTag() == TAG_ENEMY)
            this->removeChild(itemB);
    }
    return true;
}
void GameScene::mycallback(Ref* pSender)
{
    //次のシーンとして、HelloWorld2シーンをセット
    Scene* nextScene = StageScene::createScene();
    //切り替えの時間を設定。ここでは1秒
    float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    Scene* pScene = CCTransitionFade::create(duration, nextScene);
    if(pScene){
        Director::sharedDirector()->replaceScene(pScene);
    }
    
}

