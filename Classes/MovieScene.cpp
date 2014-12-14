
#include "TitleScene.h"
#include "MovieScene.h"
#include "StageScene.h"
#include "ui/UIVideoPlayer.h"


USING_NS_CC;

Scene* MovieScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MovieScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MovieScene::init()
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
    
    /*auto videoPlayer = cocos2d::experimental::ui::VideoPlayer::create();
    videoPlayer->setContentSize(visibleSize);
    videoPlayer->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    videoPlayer->setScale(0.5);
    videoPlayer->setKeepAspectRatioEnabled(true);
    this->addChild(videoPlayer);
                             
    auto menu2 = Menu::createWithItem(MenuItemLabel::create(Label::createWithSystemFont("Play", "Arial", 24),
                [videoPlayer](Ref *sender) {
                   
                 videoPlayer->setFileName("pv.mp4");
                    
                 videoPlayer->play();
                 CCLOG("hoge");
                }
                ));
                menu2->setPosition(visibleSize / 2);
                this->addChild(menu2);
    */
    
                             
    auto closeItem = MenuItemImage::create(
                                           "btn_start_en.png",
                                           "btn_start_en.png",
                                           CC_CALLBACK_1(MovieScene::myCallback, this));
    
    //closeItem->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    closeItem->setPosition(Vec2(visibleSize.width/2 + origin.x, 200));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Movie", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    
    auto videoPlayer = cocos2d::experimental::ui::VideoPlayer::create();
    videoPlayer->setContentSize(Size(128,128));
   
    //videoPlayer->cocos2d::Node::setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //videoPlayer->cocos2d::Node::setPosition(Vec2(0,0));
    
   // videoPlayer->setFullScreenEnabled(true);
    videoPlayer->setFileName("eight_four.mp4");
    //videoPlayer->setZOrder(128);
    videoPlayer->play();
    this->addChild(videoPlayer);
   

    
    
    return true;
}


void MovieScene::myCallback(Ref* pSender)
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

