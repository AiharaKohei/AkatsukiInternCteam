//
//  SimpleVideoEngine.h
//  AkatuskiIntern
//
//  Created by X-men on 2014/12/14.
//
//

#ifndef AkatuskiIntern_SimpleVideoEngine_h
#define AkatuskiIntern_SimpleVideoEngine_h

#include "cocos2d.h"

namespace befool
{
    using namespace cocos2d;
    
    class SimpleVideoEngine : public cocos2d::CCObject
    {
    public:
        void playVideo(char *path);
        static SimpleVideoEngine *getShared();
    };
}



#endif
