#include "rocket.h"
#include "logic/shot/shotmanager.h"
#ifndef PLAYERROCKET_H
#define PLAYERROCKET_H

class PlayerRocket:public Rocket
{
    ShotManager *_ShotManager;
public:
    PlayerRocket(QRect pRectangle, int pMaxHp);
    void nextMunition();
    Shot* shoot();
    virtual ~PlayerRocket();
};

#endif // PLAYERROCKET_H
