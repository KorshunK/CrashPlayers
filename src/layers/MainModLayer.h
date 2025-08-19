//
// Created by KorshunK on 19.08.2025.
//

#ifndef CRASHPLAYERS_MAINMODLAYER_H
#define CRASHPLAYERS_MAINMODLAYER_H

#include "../utils.h"

using namespace cocos2d;


class MainModLayer : public CCLayer {
protected:
    CCDirector* director = CCDirector::sharedDirector();
    virtual bool init();
    void onBack(CCObject *);
    void onCrashPlayersButton(CCObject *);
public:
    static MainModLayer* create();
    static CCScene* scene();
};


#endif //CRASHPLAYERS_MAINMODLAYER_H
