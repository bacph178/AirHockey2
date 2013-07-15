//
//  GameLayer.h
//  AirHockey
//
//  Created by Trung Kien Do on 13/07/09.
//  Copyright __FRAMGIA__ 2013年. All rights reserved.
//
#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "Ball.h"
#include "GLES-Render.h"
#include "MyContactListener.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"
#include "HttpClient.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "Menu.h"
#include "GetPresent.h"

USING_NS_CC;
using namespace cocos2d::extension;

class GameLayer : public CCLayer {
public:
    ~GameLayer();
    GameLayer();
    
    CC_SYNTHESIZE(b2World *, _world, World);
    
    static CCScene* scene();
    
    void initPhysics();
    void createEdge(float x1, float y1, float x2, float y2, int groupIndex);
    
    virtual void draw();
    void update(float dt);
    
    void getStateInfo();
    void handleProcess();
    void defenseCenter();
    void defenseLeft();
    void defenseRight();
    void attack();
    
    virtual void ccTouchesBegan(CCSet* touches, CCEvent* event);
    virtual void ccTouchesMoved(CCSet* touches, CCEvent* event);
    virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);
    
    void newTurn();
    void gameReset();
    void scoreCounter(int player);
    
    void Timer();
    void checkHighScore();
    void onHttpRequestCompleted(CCNode *sender, void *data);
    
    void endGame();
    
    b2Vec2 ptm(CCPoint point) {
        return b2Vec2(point.x / PTM_RATIO, point.y / PTM_RATIO);
    }
    b2Vec2 ptm2(float x, float y) {
        return b2Vec2(x / PTM_RATIO, y / PTM_RATIO);
    }
private:
    
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    float w = s.width;
    float h = s.height;
    
    b2Body *_groundBody;
    
    CCSprite *_p1;
    CCSprite *_p2;
    CCSprite *_endLayerBg;
    CCSprite *_rematchButton;
    CCSprite *_quitButton;
    
    GLESDebugDraw *m_debugDraw;
    
    Ball *_player1;
    Ball *_player2;
    Ball *_puck;

    b2MouseJoint *_mouseJoint;
    
    int _score1  = 0;
    int _score2  = 0;
    int lastHit = 0;
    int _minutes, _seconds;
    
    bool _playing;
    
    float x, y, px, py;
    float vx, vy, vpx, vpy;
    float pr;
    float ew, eh;
    
    CCLabelTTF *_scoreLabel1;
    CCLabelTTF *_scoreLabel2;
    CCLabelTTF *_time;
    CCLabelTTF *resultLabel = new CCLabelTTF;
    
    MyContactListener *_contactListener;
};

#endif
