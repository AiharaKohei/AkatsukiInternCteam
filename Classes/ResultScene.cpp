//
//  ResultScene.cpp
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/14.
//
//
#include "PlayScene.h"
#include "ResultScene.h"
#include "StageScene.h"



USING_NS_CC;
static const char* win_sound = "win_sound.mp3";

Scene* ResultScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ResultScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ResultScene::init()
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
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(win_sound);
    
    auto sprite = Sprite::create("win_sprite.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(sprite);

    auto closeItem = MenuItemImage::create(
                                           "home.png",
                                           "home.png",
                                           CC_CALLBACK_1(ResultScene::myCallback, this));
    
    closeItem->setPosition(Vec2(visibleSize.width/2 + origin.x, 200));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Result", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    
    
    
    return true;
}


void ResultScene::myCallback(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
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
