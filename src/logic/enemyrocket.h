#include "logic/shot.h"
#include "rocket.h"
#ifndef ENEMYROCKET_H
#define ENEMYROCKET_H

class EnemyRocket:public Rocket
{
public:
    EnemyRocket(QRect pRectangle, int pMaxHp);
    Shot* shoot();
    virtual ~EnemyRocket();
};

#endif // ENEMYROCKET_H
