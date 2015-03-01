#include "box.h"

Box::Box(QRect pRect, int pMaxHp,int pPointsToAdd):HPEntity(pRect,pMaxHp),_PointsToAdd(pPointsToAdd)
{
}

void Box::addPointsToPlayer(Player *pPlayer)
{
    pPlayer->getRocket()->addHitPoints(_PointsToAdd);
}

void Box::turnAbadBox()
{
    _PointsToAdd *= -1;
}

bool Box::isBadBox()
{
    return _PointsToAdd <= 0;
}

void Box::update()
{
    moveInPlace(0,10);
}

Box::~Box()
{

}

