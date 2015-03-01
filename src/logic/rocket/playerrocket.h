#include "rocket.h"
#include "logic/shot/shotmanager.h"
#ifndef PLAYERROCKET_H
#define PLAYERROCKET_H

class PlayerRocket:public Rocket
{
    ShotManager *_ShotManager;
    int _Combustible;
    int _SleepTimeToDecreaseCombustible;
public:
    static const int COMBUSTIBLE;
    static const int SLEEP_TIME_TO_DECREASE_COMBUSTIBLE;
    PlayerRocket(QRect pRectangle, int pMaxHp);
    void nextMunition();
    void addMunition(int pMunition);
    void addCombustible(int pCombustuble);
    int getCombustible();
    int getMunitions();
    int getMunitionType();
    void update();
    Shot* shoot();
    virtual ~PlayerRocket();
};

#endif // PLAYERROCKET_H
