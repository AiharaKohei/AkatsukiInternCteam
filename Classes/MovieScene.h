//
//  MovieScene.h
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/14.
//
//

#ifndef __AkatuskiIntern__MovieScene__
#define __AkatuskiIntern__MovieScene__

#include "cocos2d.h"
#include "SimpleVideoEngine.h"

class MovieScene : public cocos2d::Layer
{
public:
    
    virtual bool init();
    static cocos2d::Scene* createScene();
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(MovieScene);
private:
    void myCallback(cocos2d::Ref* pSender);
};

#endif /* defined(__AkatuskiIntern__MovieScene__) */
