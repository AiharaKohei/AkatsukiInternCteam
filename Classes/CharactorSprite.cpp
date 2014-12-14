//
//  CharactorSprite.cpp
//  AkatuskiIntern
//
//  Created by 相原昂平 on 2014/12/13.
//
//

#include "CharactorSprite.h"
USING_NS_CC;

Scene* CharactorSprite::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CharactorSprite::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Sprite::init() )
    {
        return false;
    }

    return true;
}