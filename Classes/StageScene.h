//
//  HelloWorldScene2.h
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/13.
//
//

#ifndef __AkatuskiIntern__HelloWorldScene2__
#define __AkatuskiIntern__HelloWorldScene2__

#include "cocos2d.h"


class StageScene : public cocos2d::Layer
{
public:
    
    virtual bool init();
    static cocos2d::Scene* createScene();
    cocos2d::Sprite* back_ground;
    cocos2d::Sprite* back_ground2;
    cocos2d::Sprite* back_ground3;
    cocos2d::Sprite* back_ground4;
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(StageScene);
private:
    void myCallback(cocos2d::Ref* pSender);
    void moveright(cocos2d::Ref* pSender);
    void moveleft(cocos2d::Ref* pSender);
};
#endif /* defined(__AkatuskiIntern__HelloWorldScene2__) */
