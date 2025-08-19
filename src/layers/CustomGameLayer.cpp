//
// Created by KorshunK on 19.08.2025.
//

#include "CustomGameLayer.h"
#include "MainModLayer.h"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool CustomGameLayer::init() {
    if(!MenuGameLayer::init()) {
        return false;
    }
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto backBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"),
            this,
            menu_selector(CustomGameLayer::onBack)
    );
    CCMenu* menuBack = CCMenu::create();
    menuBack->addChild(backBtn);
    menuBack->setPosition({25, winSize.height - 25});
    setKeypadEnabled(true);
    this->addChild(menuBack);

    CCMenu* titleMenu = CCMenu::create();
    auto title = CCLabelBMFont::create("Kill their!", "goldFont.fnt");
    titleMenu->addChild(title);
    titleMenu->setPosition((winSize.width) / 2, winSize.height - 25);
    this->addChild(titleMenu);
    return true;
}



CustomGameLayer *CustomGameLayer::create() {
    auto is = new CustomGameLayer();
    if(is && is->init()) {
        is->autorelease();
    } else {
        delete is;
        is = nullptr;
    }
    return is;
}

CCScene *CustomGameLayer::scene() {
    auto layer = CustomGameLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}

void CustomGameLayer::onBack(CCObject *) {
    auto scene = MainModLayer::scene();
    auto transition = CCTransitionFade::create(0.5f, scene);
    director->pushScene(transition);
}