#include "logic/shot.h"
#include "rocket.h"
#ifndef ENEMYROCKET_H
#define ENEMYROCKET_H

class EnemyRocket:public Rocket
{
public:
    static const int KAMIKAZE;
    static const int MOVIL_ENEMY_ROCKET;
    EnemyRocket(QRect pRectangle, int pMaxHp);
    Shot* shoot();
    virtual int getEnemyType() = 0;
    virtual ~EnemyRocket();
};

#endif // ENEMYROCKET_H
