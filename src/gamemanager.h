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
    QPixmap level;
    QPixmap enemyshot;
    QPixmap playershot;
    QPixmap indicadorSimpleshot,indicadorDifusionShot,indicadorMayhemShot;
    bool _Run;
public:
    GameManager(CrazyRiverRide *);
    void runAGame();
    int getXAxis();
    int getYAxis();
    bool shoot();
    bool pause();
    void update(google::protobuf::Message *pMessage);
    ~GameManager();
};

#endif // GAMEMANAGER_H
