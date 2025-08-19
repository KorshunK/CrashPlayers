//
// Created by KorshunK on 19.08.2025.
//

#include "TestLayer.h"

TestLayer* TestLayer::create() {
    auto is = new TestLayer();
    if(is && is->init()) {
        is->autorelease();
    } else {
        delete is;
        is = nullptr;
    }
    return is;
}

bool TestLayer::init() {
    auto background = CCSprite::create("game_bg_14_001.png");
    auto winSize = director->getWinSize();
    const CCSize &bgSize = background->getContentSize();
    background->setScale(winSize.width / bgSize.width);
    background->setAnchorPoint({0, 0});
    background->setPosition({0, -75});
    background->setColor({164, 0, 255});
    background->setZOrder(-3);
    this->addChild(background);
    auto backBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"),
            this,
            menu_selector(TestLayer::onBack)
            );
    CCMenu* menuBack = CCMenu::create();
    menuBack->addChild(backBtn);
    menuBack->setPosition({25, winSize.height - 25});
    setKeypadEnabled(true);
    this->addChild(menuBack);
//    auto mainLayer = MenuLayer::scene(false);
//    director->pushScene(mainLayer);
    return true;
}

void TestLayer::keyBackClicked() {
    director->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void TestLayer::onBack(cocos2d::CCObject *) {
    keyBackClicked();
}

CCScene* TestLayer::scene() {
    auto layer = TestLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}