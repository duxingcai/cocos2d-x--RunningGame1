#include "HelloWorldScene.h"
#include "SettingScene.h"
#include "HelpScene.h"
#include "GameScene.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //退出游戏按钮菜单项
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    //背景
    Sprite *bg=Sprite::create("Menu_002.png");
    bg->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(bg);
    
    //开始精灵
    Sprite *startSpriteNormal=Sprite::create("start-up.png");
    Sprite *startSpriteSelected=Sprite::create("start-down.png");
    
    MenuItemSprite *startMenuItem=MenuItemSprite::create(startSpriteNormal,startSpriteSelected,
                                                         CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
    startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(760, 160)));
    
    
    //设置图片菜单
    MenuItemImage *settingMenuItem=MenuItemImage::create("setting-up.png","setting-down.png",
                                                         CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
    
    settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(580,400)));
    
    //帮助图片菜单
    MenuItemImage *helpMenuItem=MenuItemImage::create("help-up.png","help-down.png",
                                    CC_CALLBACK_1(HelloWorld::menuItemHelpCallback, this));
    
    helpMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(900,560)));
    
    Menu *mu=Menu::create(startMenuItem,settingMenuItem,helpMenuItem,NULL);
    mu->setPosition(Vec2::ZERO);
    this->addChild(mu);
    
    // create and initialize a label
    
    auto label = LabelTTF::create("Parkour Game", "Arial", 44);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height+(20)));
    
    // add the label as a child to this layer
    this->addChild(label,1);

    return true;
}

void HelloWorld::menuItemSettingCallback(Ref *pSender)
{
    auto sc=Setting::createScene();
    //Director::getInstance()->replaceScene(sc);
    
    Director::getInstance()->pushScene(sc);
}



void HelloWorld::menuItemHelpCallback(Ref *pSender)
{   auto sc1=Help::createScene();
   // MenuItem *item=(MenuItem*)pSender;
    Director::getInstance()->pushScene(sc1);
    //log("Touch Help %p",item);
}


void HelloWorld::menuItemStartCallback(Ref *pSender)
{
    auto sc2=Game::createScene();
    
    Director::getInstance()->pushScene(sc2);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("");
    //MenuItem *item=(MenuItem *)pSender;
   // log("Touch Start %p",item);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
