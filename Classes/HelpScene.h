//
//  HelpScene.h
//  Menu
//
//  Created by 杜杜兴 on 15/6/14.
//
//

#ifndef __Menu__HelpScene__
#define __Menu__HelpScene__

#include "cocos2d.h"

class Help : public cocos2d::Layer
{
public:
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    
    virtual bool init();
    
    void menuExplainCallback(cocos2d::Ref* pSender);
    void menuOkCallback(cocos2d::Ref* pSender);
    
    
    CREATE_FUNC(Help)
};


#endif /* defined(__Menu__HelpScene__) */
