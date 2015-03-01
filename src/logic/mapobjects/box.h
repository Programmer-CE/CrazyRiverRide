#include "logic/mapobjects/hpentity.h"
#include "logic/player.h"

#ifndef BOX_H
#define BOX_H

class Box: public HPEntity
{
protected:
    int _PointsToAdd;
public:
    Box(QRect pRect, int pMaxHp,int pPointsToAdd);
    virtual void addPointsToPlayer(Player *pPlayer);
    void turnAbadBox();
    bool isBadBox();
    void update();
    virtual ~Box();
};

#endif // BOX_H
