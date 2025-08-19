//
// Created by KorshunK on 19.08.2025.
//

#include "MainModLayer.h"
#include "CustomGameLayer.h"

#include <Geode/ui/BasedButtonSprite.hpp>
#include <Geode/Geode.hpp>

using namespace geode;
using namespace geode::prelude;

MainModLayer* MainModLayer::create() {
    auto is = new MainModLayer();
    if(is && is->init()) {
        is->autorelease();
    } else {
        delete is;
        is = nullptr;
    }
    return is;
}

bool MainModLayer::init() {
    //Background
    auto background = CCSprite::create("game_bg_26_001.png");
    auto winSize = director->getWinSize();
    const CCSize &bgSize = background->getContentSize();
    background->setScale(winSize.width / bgSize.width);
    background->setAnchorPoint({0, 0});
    background->setPosition({0, -75});
    background->setColor({164, 0, 255});
    background->setZOrder(-3);
    this->addChild(background);

    // Title
    CCMenu* titleMenu = CCMenu::create();
    titleMenu->setPosition(winSize.width / 2, winSize.height - 25);
    auto title = CCLabelBMFont::create("CrashPlayers", "goldFont.fnt");
    titleMenu->addChild(title);

    this->addChild(titleMenu);

    //Back button
    auto backBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"),
            this,
            menu_selector(MainModLayer::onBack)
    );
    CCMenu* menuBack = CCMenu::create();
    menuBack->addChild(backBtn);
    menuBack->setPosition({25, winSize.height - 25});
    setKeypadEnabled(true);
    this->addChild(menuBack);

    // Main menu
    CCMenu* mainMenu = CCMenu::create();
    mainMenu->setContentSize({winSize.width - 50, winSize.height - 25});

    auto crashPlayersBtnSprite = CCSprite::create("CP_crashBtn_001.png"_spr);
    crashPlayersBtnSprite->setScale(0.75f);
    auto crashPlayersBtn = CCMenuItemSpriteExtra::create(
            crashPlayersBtnSprite,
            this,
            menu_selector(MainModLayer::onCrashPlayersButton)
            );
    mainMenu->addChild(crashPlayersBtn);

//    mainMenu->setPosition(winSize.width / 2, winSize.height / 2);
    this->addChild(mainMenu);
    return true;
}

void MainModLayer::onCrashPlayersButton(CCObject *) {
    auto scene = CustomGameLayer::scene();
    auto transition = CCTransitionFade::create(0.5f, scene);
    director->pushScene(transition);
}

void MainModLayer::onBack(cocos2d::CCObject *) {
    auto scene = MenuLayer::scene(false);
    auto transition = CCTransitionFade::create(0.5f, scene);
    director->pushScene(transition);
}

CCScene* MainModLayer::scene() {
    auto layer = MainModLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}