//
//  RankingScene.h
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/14.
//
//

#ifndef __AkatuskiIntern__RankingScene__
#define __AkatuskiIntern__RankingScene__

#include "cocos2d.h"

class RankingScene : public cocos2d::Layer
{
public:
    
    virtual bool init();
    static cocos2d::Scene* createScene();
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(RankingScene);
private:
    void myCallback(cocos2d::Ref* pSender);
};


#endif /* defined(__AkatuskiIntern__RankingScene__) */
