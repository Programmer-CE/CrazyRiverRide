#include "logic/rocket/enemyrocket.h"
#ifndef MOVILENEMYROCKET_H
#define MOVILENEMYROCKET_H

class MovilEnemyRocket:public EnemyRocket
{
public:
    MovilEnemyRocket(QRect pRectangle, int pMaxHp);
    int getEnemyType();
    void update();
};

#endif // MOVILENEMYROCKET_H
