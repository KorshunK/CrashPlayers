//
// Created by KorshunK on 19.08.2025.
//

#ifndef TEST_CUSTOMGAMELAYER_H
#define TEST_CUSTOMGAMELAYER_H

using namespace cocos2d;


class CustomGameLayer : public MenuGameLayer {
protected:
    CCDirector* director = CCDirector::sharedDirector();
    virtual bool init();
    void onBack(CCObject*);
public:
    static CCScene* scene();
    static CustomGameLayer* create();
};


#endif //TEST_CUSTOMGAMELAYER_H
