//
//  GameScene.cpp
//  Menu
//
//  Created by 杜杜兴 on 15/6/14.
//
//

#include "GameScene.h"
#include"HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* Game::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Game::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Game::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    //添加背景
    Sprite *bg=Sprite::create("bg_001.jpg");
    bg->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    this->addChild(bg);
    
    //播放背景音乐
    SimpleAudioEngine::getInstance()->playBackgroundMusic("i_comic.ogg",true);
    
    /*//Ok按钮
    auto okMenuItem  = MenuItemImage::create(
                                             "ok-down.png",
                                             "ok-up.png",
                                             CC_CALLBACK_1(Game::menuOkCallback, this));
    
    okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(600, 600)));
    
    Menu* mn = Menu::create(okMenuItem, NULL);
    mn->setPosition(Vec2(visibleSize.width/2-175,visibleSize.height/2-380));
    this->addChild(mn);*/
    
    //下雪粒子
    auto particleSystem=ParticleSystemQuad::create("snow.plist");
    particleSystem->setPosition(Vec2(visibleSize.width/2,visibleSize.height));
    this->addChild(particleSystem);
    
    
    //返回主菜单
    MenuItemFont::setFontName("Times New Roman");
    MenuItemFont::setFontSize(30);
    
    MenuItemFont *item1=MenuItemFont::create("返回菜单",
                                             CC_CALLBACK_1(Game::menuItem1Callback, this));
    Menu *mn1=Menu::create(item1,NULL);
    //mn1->alignItemsVertically();
    mn1->setPosition(Vec2(visibleSize.width/2+480,visibleSize.height/2-325));
    this->addChild(mn1);
    return true;
    
}

/*
void Game::menuOkCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}
*/
 
void Game::menuItem1Callback(cocos2d::Ref *pSender)
{
    Director::getInstance()->popScene();
}
/*
void Game::GameOver()
{
    Director::getInstance()->pause();
    auto over=MenuItemFont::create("Game Over",CC_CALLBACK_1(GameScene::menuOkCallback, this));
    over->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    over->setScale(3);
    auto menu=Menu::create(over,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
   
}
*/