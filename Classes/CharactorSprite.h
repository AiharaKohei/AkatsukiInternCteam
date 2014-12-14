//
//  CharactorSprite.h
//  AkatuskiIntern
//
//  Created by 相原昂平 on 2014/12/13.
//
//

#ifndef __AkatuskiIntern__CharactorSprite__
#define __AkatuskiIntern__CharactorSprite__

#include "cocos2d.h"
using namespace cocos2d;

class CharactorSprite : public Sprite
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    CREATE_FUNC(HelloWorld);
};

#endif /* defined(__AkatuskiIntern__CharactorSprite__) */
