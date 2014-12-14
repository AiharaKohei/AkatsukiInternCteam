//
//  ResultScene.h
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/14.
//
//

#ifndef __AkatuskiIntern__ResultScene__
#define __AkatuskiIntern__ResultScene__


#include "cocos2d.h"
#include "SimpleAudioEngine.h"



class ResultScene : public cocos2d::Layer
{
public:
    
    virtual bool init();
    static cocos2d::Scene* createScene();
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(ResultScene);
private:
    void myCallback(cocos2d::Ref* pSender);
};

#endif /* defined(__AkatuskiIntern__ResultScene__) */
