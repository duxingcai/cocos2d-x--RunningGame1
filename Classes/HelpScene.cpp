//
//  HelpScene.cpp
//  Menu
//
//  Created by 杜杜兴 on 15/6/14.
//
//

#include "HelpScene.h"
USING_NS_CC;

Scene* Help::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Help::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Help::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *bg = Sprite::create("blue_001.jpg");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    this->addChild(bg);
    //Ok按钮
    auto okMenuItem  = MenuItemImage::create(
                                             "ok-down.png",
                                             "ok-up.png",
                                             CC_CALLBACK_1(Help::menuOkCallback, this));
    
    okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(600, 510)));
    
    Menu* mn = Menu::create(okMenuItem, NULL);
    mn->setPosition(Vec2::ZERO);
    this->addChild(mn);
    
    //添加文字解释说明
    // create and initialize a label
    
    auto label = LabelTTF::create("Parkour Game", "Arial", 44);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height+(15)));
    
    // add the label as a child to this layer
    this->addChild(label,1);

    
    auto label1 = LabelTTF::create("用户使用说明", "Arial", 34);
    
    // position the label on the center of the screen
    label1->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label1->getContentSize().height+(-65)));
    
    // add the label as a child to this layer
    this->addChild(label1,1);
    
    auto label2 = LabelTTF::create("用户点击屏幕任意位置，精灵产生跳跃。", "Arial", 20);
    
    // position the label on the center of the screen
    label2->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label2->getContentSize().height+(-155)));
    
    // add the label as a child to this layer
    this->addChild(label2,1);
    
    
    
    auto label3 = LabelTTF::create("本游戏归属为冒险类游戏，此游戏为杜杜兴倾力制作!", "Arial", 20);
    
    // position the label on the center of the screen
    label3->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label2->getContentSize().height+(-215)));
    
    // add the label as a child to this layer
    this->addChild(label3,1);
    
    
    auto label4 = LabelTTF::create("游戏操作简单，主菜单提供音效设置选项,您可根据需要设置!", "Arial", 20);
    
    // position the label on the center of the screen
    label4->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label2->getContentSize().height+(-185)));
    
    // add the label as a child to this layer
    this->addChild(label4,1);
    
    auto label5= LabelTTF::create("@版权归杜杜兴所有！", "Arial", 20);
    
    // position the label on the center of the screen
    label5->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label2->getContentSize().height+(-245)));
    
    // add the label as a child to this layer
    this->addChild(label5,1);
    
    return true;
}

void Help::menuOkCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
    
}