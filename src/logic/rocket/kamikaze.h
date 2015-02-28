#include "enemyrocket.h"
#include "logic/player.h"
#ifndef KAMIKAZE_H
#define KAMIKAZE_H

class Kamikaze:public EnemyRocket
{
    Player *_PlayerToFollow;
public:
    Kamikaze(QRect pRectangle, int pMaxHp,Player * pPlayerToFollow);
    int getEnemyType();
    void update();
};

#endif // KAMIKAZE_H
