//
//  RankingScene.h
//  AirHockey
//
//

#ifndef __AirHockey__RankingScene__
#define __AirHockey__RankingScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
class RankingScene : public CCLayer
{
private:
    CCSize size = CCDirector::sharedDirector()->getWinSize();
public:
    virtual bool init();
    static CCScene* scene();
    void onHttpRequestCompleted(CCNode *sender, void *data);
    CREATE_FUNC(RankingScene);
    
    void menuPlay(CCObject* pSender);
    void menuMenu(CCObject* pSender);
};
#endif /* defined(__AirHockey__RankingScene__) */