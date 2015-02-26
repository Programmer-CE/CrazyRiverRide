#include "enemyrocket.h"
#ifndef KAMIKAZE_H
#define KAMIKAZE_H

class Kamikaze:public EnemyRocket
{
public:
    Kamikaze(QRect pRectangle, int pMaxHp);
};

#endif // KAMIKAZE_H
