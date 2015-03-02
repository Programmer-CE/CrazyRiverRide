#include "crazyriverride.h"
#include "logic/patterdesing/observer.h"
#include "qpixmap.h"
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager:public Observer
{
    CrazyRiverRide *_GameWindows;
    QRect r;
    QPixmap player1;
    QPixmap enemies;
    QPixmap level,level2,level3,level4,level5;
    QPixmap enemyshot;
    QPixmap playershot;
    QPixmap *currentMap;
    QPixmap indicadorSimpleshot,indicadorDifusionShot,indicadorMayhemShot;
    QPixmap boxAmount,boxHp,boxBadHp,boxCombustible,boxBadCombustible;
    bool _Run;
public:
    GameManager(CrazyRiverRide *);
    void runAGame();
    int getXAxis();
    int getYAxis();
    bool shoot();
    bool pause();
    void select(int Map);
    void update(google::protobuf::Message *pMessage);
    virtual ~GameManager();
};

#endif // GAMEMANAGER_H
