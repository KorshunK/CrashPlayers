#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

#include "layers/MainModLayer.h"


class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }
        CCSprite* enterButtonSprite = CCSprite::createWithSpriteFrameName("GJ_editBtn_001.png");
        enterButtonSprite->setScale(0.4f);
        auto enterMenuButton = CCMenuItemSpriteExtra::create(
                enterButtonSprite,
                this,
                menu_selector(MyMenuLayer::onEnterMenuButton)
        );
        auto menu = this->getChildByID("side-menu");
        menu->addChild(enterMenuButton);

        enterMenuButton->setID("enter_menu_button"_spr);

        menu->updateLayout();
        return true;
    }

    void onEnterMenuButton(CCObject*) {
        auto scene = MainModLayer::scene();
        auto transition = CCTransitionFade::create(0.5f, scene);
        CCDirector::sharedDirector()->pushScene(transition);
    }
};