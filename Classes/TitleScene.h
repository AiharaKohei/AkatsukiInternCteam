#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class TitleScene : public cocos2d::Layer
{
public:
    
    virtual bool init();
    static cocos2d::Scene* createScene();
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(TitleScene);
private:
    void myCallback(cocos2d::Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
