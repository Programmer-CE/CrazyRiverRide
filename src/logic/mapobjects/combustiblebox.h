#include "logic/mapobjects/box.h"
#ifndef COMBUSTIBLEBOX_H
#define COMBUSTIBLEBOX_H

class CombustibleBox:public Box
{
public:
    CombustibleBox(QRect pRect, int pMaxHp,int pPointsToAdd);
    void addPointsToPlayer(Player *pPlayer);
    void update();
    virtual ~CombustibleBox();

};

#endif // COMBUSTIBLEBOX_H
