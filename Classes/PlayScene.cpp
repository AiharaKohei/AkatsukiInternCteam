#include "PlayScene.h"
#include "RankingScene.h"
#include "ResultScene.h"

USING_NS_CC;
#define TAG_CHARA 0
#define TAG_ENEMY 1
#define TAG_BOMB 2
#define TAG_WALL 3
#define TAG_BULLET 4


Scene* PlayScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    
    // 'layer' is an autorelease object
    auto layer = PlayScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    spriteVector.clear();
    isFristTouch = true;
    
    
    Sprite *background = Sprite::create("stage1.png");
    background->setPosition(Vec2(visibleSize.width/2-5, visibleSize.height/2));
    this->addChild(background);
    
    cNode = ClippingNode::create();
    cNode->setPosition(Vec2::ZERO);
    this->addChild(cNode, 4);
    //
    Sprite *mask = Sprite::create("mask.png");
    mask->setPosition(50, visibleSize.height/2 + 235);
    cNode->setStencil(mask);
    //    this->addChild(mask);
    
    Sprite *lifeGageBar = Sprite::create("lifeGageBar.png");
    lifeGageBar->setPosition(Vec2(visibleSize.width/2-5, visibleSize.height/2));
    this->addChild(lifeGageBar, 5);
    
    Sprite *lifeGageFull = Sprite::create("lifeGageFull.png");
    lifeGageFull->setPosition(Vec2(visibleSize.width/2-5, visibleSize.height/2));
    cNode->addChild(lifeGageFull, 4);
    Sprite *lifeGageHalf = Sprite::create("lifeGageHalf.png");
    lifeGageHalf->setPosition(Vec2(visibleSize.width/2-5, visibleSize.height/2));
    cNode->addChild(lifeGageHalf, 4);
    Sprite *lifeGageShort = Sprite::create("lifeGageShort.png");
    lifeGageShort->setPosition(Vec2(visibleSize.width/2-5, visibleSize.height/2));
    cNode->addChild(lifeGageShort, 4);
    
    
    this->setListenner();
    this->setCornerWall();
    
    
    for (int i = 0; i < 50; i++) {
        int randX = rand() % 100;
        int randY = rand() % 100;
        
        Sprite *chara = Sprite::create("nomi.png");
        chara->setScale(0.2);
        chara->setPosition(Point(visibleSize.width/2 * (randX / 100.0 + 0.5), visibleSize.height/4 * randY / 100.0));
        PhysicsBody *pBody = PhysicsBody::createCircle(10);
        pBody->setContactTestBitmask(2);
        chara->setTag(TAG_CHARA);
        chara->setPhysicsBody(pBody);
        this->addChild(chara);
        spriteVector.pushBack(chara);
    }
    
    enemy = Sprite::create("mimizu.png");
    enemy->setScale(1.7);
    enemy->setPosition(Point(visibleSize.width / 2, visibleSize.height - 200));
    PhysicsBody *pBody = PhysicsBody::createBox(Size(60, 200));
    pBody->setContactTestBitmask(1);
    enemy->setTag(TAG_ENEMY);
    enemy->setPhysicsBody(pBody);
    this->addChild(enemy);
    enemyHp = 20;
    
    for (int i = 0; i < 4; i++) {
        int randX = rand() % 100;
        int randY = rand() % 100;
        Sprite *bomb = Sprite::create("bomb.png");
        bomb->setPosition(Point(visibleSize.width/2  * (randX /100.0 + 0.5), visibleSize.height /2   * (randY / 100.0 + 0.5)));
        PhysicsBody *pBodybomb = PhysicsBody::createCircle(19);
        pBodybomb->setContactTestBitmask(2);
        bomb->setTag(TAG_BOMB);
        bomb->setPhysicsBody(pBodybomb);
        this->addChild(bomb);
    }
    
    
    
    auto materialTrap = PHYSICSBODY_MATERIAL_DEFAULT;
    materialTrap.restitution = 2.0;
    
    auto wall1 = Sprite::create("wall.png");
    wall1->setPosition(visibleSize.width/2 - 100, visibleSize.height/2 + 200);
    wall1->setRotation(-45);
    wall1->setTag(TAG_WALL);
    
    auto pWall1 = PhysicsBody::createBox(wall1->getContentSize(), materialTrap);
    pWall1->setDynamic(false);
    pWall1->setRotationEnable(false);
    wall1->setPhysicsBody(pWall1);
    addChild(wall1);
    
    auto wall2 = Sprite::create("wall.png");
    wall2->setPosition(visibleSize.width/2 + 100, visibleSize.height/2 - 200);
    wall2->setRotation(45);
    wall2->setTag(TAG_WALL);
    
    auto pWall2 = PhysicsBody::createBox(wall2->getContentSize(), materialTrap);
    pWall2->setDynamic(false);
    pWall2->setRotationEnable(false);
    wall2->setPhysicsBody(pWall2);
    addChild(wall2);
    
    
//    this->schedule(schedule_selector(PlayScene::shotEnemyBullet), 3.0);
    
    return true;
}
void PlayScene::shotEnemyBullet(float dt) {
//    auto bullet = Sprite::create("bullet.png");
//    bullet->setPosition(Vec2(enemy->getPosition().x, enemy->getPositionY()  - enemy->getContentSize().height - 20));
//    bullet->setTag(TAG_BULLET);
//    bullet->setScale(0.3);
//    
//    auto pBullet = PhysicsBody::createBox(Size(30, 30), PHYSICSBODY_MATERIAL_DEFAULT);
//    pBullet->setDynamic(true);
//    pBullet->setRotationEnable(false);
//    bullet->setPhysicsBody(pBullet);
//    pBullet->setContactTestBitmask(3);
//    addChild(bullet);
//    
//    int randX = rand() % 100;
//    Vec2 vec = Vec2(0.5 / randX, -1.0);
//    pBullet->setVelocity(80.0 * vec);
}

void PlayScene::setListenner(){
    Director::getInstance()->getEventDispatcher()->setEnabled(true);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(PlayScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(PlayScene::onTouchEnded, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    auto p_listener = EventListenerPhysicsContact::create();
    p_listener->onContactBegin = CC_CALLBACK_1(PlayScene::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(p_listener, this);
}

void PlayScene::setCornerWall(){
    auto wallBottom = Sprite::create();
    wallBottom->setPosition(visibleSize.width/2, 20);
    wallBottom->setTextureRect(Rect(0,0,visibleSize.width,10));
    wallBottom->setOpacity(0);
    wallBottom->setTag(TAG_WALL);
    
    
    auto pWallBottom = PhysicsBody::createBox(wallBottom->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
    pWallBottom->setDynamic(false);
    pWallBottom->setRotationEnable(false);
    wallBottom->setPhysicsBody(pWallBottom);
    addChild(wallBottom);
    
    
    auto wallTop = Sprite::create();
    wallTop->setPosition(visibleSize.width/2, visibleSize.height- 20);
    wallTop->setTextureRect(Rect(0,0,visibleSize.width,10));
    wallTop->setOpacity(0);
    wallTop->setTag(TAG_WALL);

    auto pWallTop = PhysicsBody::createBox(wallTop->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
    pWallTop->setDynamic(false);
    pWallTop->setRotationEnable(false);
    wallTop->setPhysicsBody(pWallTop);
    addChild(wallTop);
    
    
    auto wallLeft = Sprite::create();
    wallLeft->setPosition(20, visibleSize.height/2);
    wallLeft->setTextureRect(Rect(0,0,10,visibleSize.height));
    wallLeft->setOpacity(0);
    wallLeft->setTag(TAG_WALL);
    
    
    auto pWallLeft = PhysicsBody::createBox(wallLeft->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
    pWallLeft->setDynamic(false);
    pWallLeft->setRotationEnable(false);
    wallLeft->setPhysicsBody(pWallLeft);
    addChild(wallLeft);
    
    auto wallRight = Sprite::create();
    wallRight->setPosition(visibleSize.width -20, visibleSize.height/2);
    wallRight->setTextureRect(Rect(0,0,10,visibleSize.height));
    wallRight->setOpacity(0);
    wallRight->setTag(TAG_WALL);
    
    
    auto pWallRight = PhysicsBody::createBox(wallRight->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);
    pWallRight->setDynamic(false);
    pWallRight->setRotationEnable(false);
    wallRight->setPhysicsBody(pWallRight);
    addChild(wallRight);
}

bool PlayScene::onTouchBegan(Touch *pTouch, Event *pEvent){
    
    Vector<Sprite*>::iterator the_iterator = spriteVector.begin();
    while(the_iterator != spriteVector.end()) {
        
        Sprite *chara  = *the_iterator;
        the_iterator++;
        
        chara->getPhysicsBody()->setVelocity(Vec2(0, 500));
        
        Vec2 forceVec2 = Vec2(chara->getPosition() - pTouch->getLocation());
        float vecLength = 100000 / sqrtf(forceVec2.x * forceVec2.x + forceVec2.y * forceVec2.y);
        if(vecLength > 700)
            vecLength = 1000;
        Vec2 forceVec2Normal = forceVec2.getNormalized();
        
        chara->getPhysicsBody()->setVelocity(vecLength * forceVec2Normal);
        
    }
    
    return true;
}

void PlayScene::onTouchMoved(Touch *pTouch, Event *pEvent){
    
}

void PlayScene::onTouchEnded(Touch *pTouch, Event *pEvent){
    
}

bool PlayScene::onContactBegin(cocos2d::PhysicsContact &contact){
    Sprite *itemA = dynamic_cast<Sprite*>(contact.getShapeA()->getBody()->getNode());
    Sprite *itemB = dynamic_cast<Sprite*>(contact.getShapeB()->getBody()->getNode());
    
    if (!itemA | !itemB) return false;
    if (itemA->getTag() == TAG_CHARA && itemB->getTag() == TAG_CHARA) return true;
    
//    if (itemA->getTag() == TAG_BULLET) {
//        log("bullet");
//        if (itemB->getTag() == TAG_CHARA)
//            this->applayForceFromBomb(itemA->getPosition());
//        this->removeChild(itemA);
//        return true;
//    }
//    if (itemB->getTag() == TAG_BULLET) {
//        log("bullet");
//
//        if (itemA->getTag() == TAG_CHARA)
//            this->applayForceFromBomb(itemB->getPosition());
//        this->removeChild(itemB);
//        return true;
//    }
    
    
    this->fireBombEffect(itemA->getPosition());
    
    if (itemA->getTag() == TAG_ENEMY | itemA->getTag() == TAG_BOMB){
        if (itemA->getTag() == TAG_BOMB){
            this->applayForceFromBomb(itemA->getPosition());
            this->removeChild(itemA);
            return true;
        } else {
            enemyHp--;
            this->changeGageParamata();
            spriteVector.eraseObject(itemB);
            itemB->runAction(Sequence::create(FadeOut::create(1.0), RemoveSelf::create(), NULL));
            this->explosionEnemy(itemA);
            return true;
        }
    }
    
    if (itemB->getTag() == TAG_ENEMY | itemB->getTag() == TAG_BOMB){
        if (itemB->getTag() == TAG_BOMB){
            this->applayForceFromBomb(itemB->getPosition());
            this->removeChild(itemB);
            return true;
        } else {
            enemyHp--;
            this->changeGageParamata();
            spriteVector.eraseObject(itemA);
            itemA->runAction(Sequence::create(FadeOut::create(1.0), RemoveSelf::create(), NULL));
            this->explosionEnemy(itemB);
            return true;
        }
    }
    return true;
}

void PlayScene::applayForceFromBomb(cocos2d::Vec2 bombPosition){
    Vector<Sprite*>::iterator the_iterator = spriteVector.begin();
    while(the_iterator != spriteVector.end()) {
        
        Sprite *chara  = *the_iterator;
        the_iterator++;
        
        log("chara x %f   y %f", chara->getPositionX(), chara->getPositionY());
        log("bomb x %f   y %f", bombPosition.x, bombPosition.y);
        
        Vec2 forceVec2 = Vec2(chara->getPosition().x - bombPosition.x, chara->getPosition().y - bombPosition.y);
        float vecLength = 100000 / sqrtf(forceVec2.x * forceVec2.x + forceVec2.y * forceVec2.y);
        if(vecLength > 700)
            vecLength = 700;
        if (vecLength < 400) continue;
        Vec2 forceVec2Normal = forceVec2.getNormalized();
        if (vecLength > 600) {
            spriteVector.eraseObject(chara);
            chara->runAction(Sequence::create(FadeOut::create(1.0), RemoveSelf::create(), NULL));
        } else {
            chara->getPhysicsBody()->setVelocity(vecLength * forceVec2Normal);
        }
    }
    
}

void PlayScene::fireBombEffect(cocos2d::Vec2 bombPosition){
    Sprite *bomEffect = Sprite::create("feverDamage.png");
    bomEffect->setScale(0.0);
    bomEffect->setPosition(bombPosition);
    this->addChild(bomEffect);
    bomEffect->runAction(Sequence::create(ScaleTo::create(0.2, 0.7), RemoveSelf::create(), NULL));
}

void PlayScene::explosionEnemy(cocos2d::Sprite *enemy){
    if (enemyHp <= 0) {
        Sprite *bomEffect = Sprite::create("feverDamage.png");
        bomEffect->setScale(0.0);
        bomEffect->setPosition(enemy->getPosition());
        this->addChild(bomEffect);
        bomEffect->runAction(Sequence::create(ScaleTo::create(0.2, 2.0), RemoveSelf::create(), NULL));
        
        this->removeChild(enemy);
        
        //次のシーンとして、HelloWorld2シーンをセット
        Scene* nextScene = ResultScene::createScene();
        //切り替えの時間を設定。ここでは1秒
        float duration = 2.0;
        //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
        Scene* pScene = CCTransitionFade::create(duration, nextScene);
        if(pScene){
            Director::getInstance()->replaceScene(pScene);
        }

    }
}

void PlayScene::changeGageParamata(){
    Sprite *mask = dynamic_cast<Sprite*>(cNode->getStencil());
    if (mask) {
        log("tetetet");
    }
    mask->runAction(MoveBy::create(0.3, Vec2(0, -1.0 / 20.0 * 463)));
}
