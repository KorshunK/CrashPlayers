//
// Created by KorshunK on 19.08.2025.
//

#ifndef TEST_TESTLAYER_H
#define TEST_TESTLAYER_H

using namespace cocos2d;


class TestLayer : public CCLayer {
protected:
    CCDirector* director = CCDirector::sharedDirector();
    virtual bool init();
    virtual void keyBackClicked();
    void onBack(CCObject*);
public:
    static TestLayer* create();
    static CCScene* scene();
};


#endif //TEST_TESTLAYER_H
