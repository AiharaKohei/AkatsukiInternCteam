//
//  HelloWorldScene2.cpp
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/13.
//
//

#include "RankingScene.h"
#include "StageScene.h"
#include "ResultScene.h"
#include "PlayScene.h"



USING_NS_CC;
int count = 1;
Scene* StageScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StageScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StageScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    back_ground = Sprite::create("background.png");
    back_ground->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    
    
    auto back_ground3 = Sprite::create("background3.png");
    back_ground3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    //auto back_ground4 = Sprite::create("background4.png");
    //back_ground4->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
   // back_ground2->setVisible(false);
   // back_ground3->setVisible(false);
   // back_ground4->setVisible(false);
    
    
    this->addChild(back_ground);
    
    
    auto right = MenuItemImage::create(
                                        "right.png",
                                        "right.png",
                                       CC_CALLBACK_1(StageScene::moveright,this));
    right->setPosition(Vec2(visibleSize.width/2 + origin.x + 250, visibleSize.height/2 + origin.y));
    
    auto left = MenuItemImage::create(
                                       "left.png",
                                       "left.png",
                                       CC_CALLBACK_1(StageScene::moveleft,this));
    left->setPosition(Vec2(visibleSize.width/2 + origin.x - 250, visibleSize.height/2 + origin.y));

    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "stage_btn.png",
                                           "stage_btn.png",
                                           CC_CALLBACK_1(StageScene::myCallback, this));
    
    closeItem->setPosition(Vec2(visibleSize.width/2 + origin.x, 100));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, right, left, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->setContentSize(Size(30,30));
    this->addChild(menu, 1);
    
  

    
   // removeChild(<#cocos2d::Node *child#>);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Stage", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    
    
    
    return true;
}
void StageScene::moveright(Ref* pSender)
{
    if(count == 0){
       // back_ground->setVisible(false);
        auto back_ground1 = Sprite::create("background.png");
        
        back_ground1->setPosition(back_ground->getPosition());
        this->addChild(back_ground1);
        count++;
    }
    else if(count == 1){
    back_ground->setVisible(false);
    auto back_ground2 = Sprite::create("background2.png");
    back_ground2->setPosition(back_ground->getPosition());
    this->addChild(back_ground2);
        count++;
    }else if(count == 2){
        //back_ground2->setVisible(false);
        auto back_ground3 = Sprite::create("background3.png");
        back_ground3->setPosition(back_ground->getPosition());
        this->addChild(back_ground3);
        count++;
    }else if(count == 3){
        //back_ground3->setVisible(false);
        auto back_ground4 = Sprite::create("background4.png");
        back_ground4->setPosition(back_ground->getPosition());
        this->addChild(back_ground4);
        count = 0;
    }
}

void StageScene::moveleft(Ref* pSender)
{
    back_ground->setVisible(false);
    auto back_ground4 = Sprite::create("background4.png");
    back_ground4->setPosition(back_ground->getPosition());
    this->addChild(back_ground4);
}


void StageScene::myCallback(Ref* pSender)
{
    //次のシーンとして、HelloWorld2シーンをセット
    Scene* nextScene = PlayScene::createScene();
    //切り替えの時間を設定。ここでは1秒
    float duration = 1.0f;
    //フェードイン＆フェードアウト（CCTransitionFade）でトランジショーーーン
    Scene* pScene = CCTransitionFade::create(duration, nextScene);
    if(pScene){
        Director::getInstance()->replaceScene(pScene);
    }
    
}

