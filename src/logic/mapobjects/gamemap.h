#include "gameobject.h"
#ifndef GAMEMAP_H
#define GAMEMAP_H

class GameMap:public GameObject
{
    int _Vy,_Limit;
public:
    GameMap(QRect pRect,int pVy, int pLimit);
    void update();
};

#endif // GAMEMAP_H
