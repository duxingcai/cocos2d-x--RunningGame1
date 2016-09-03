//
//  GameScene.h
//  Menu
//
//  Created by 杜杜兴 on 15/6/14.
//
//

#ifndef __Menu__GameScene__
#define __Menu__GameScene__

#include "cocos2d.h"

class Game: public cocos2d::Layer
{
public:
    void GameOver();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    //void menuSoundToggleCallback(cocos2d::Ref* pSender);
    //void menuMusicToggleCallback(cocos2d::Ref* pSender);
    void menuOkCallback(cocos2d::Ref* pSender);
    
    void menuItem1Callback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Game);
};
#endif /* defined(__Menu__GameScene__) */
