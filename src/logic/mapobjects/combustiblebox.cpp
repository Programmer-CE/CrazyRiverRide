#include "combustiblebox.h"

CombustibleBox::CombustibleBox(QRect pRect, int pMaxHp,int pPointsToAdd):Box(pRect,pMaxHp,pPointsToAdd)
{
}

void CombustibleBox::addPointsToPlayer(Player *pPlayer)
{
    if (!isBadBox())pPlayer->getRocket()->addCombustible(_PointsToAdd);
    else pPlayer->getRocket()->addHitPoints(_PointsToAdd);
}

void CombustibleBox::update()
{
    moveInPlace(0,10);
}

CombustibleBox::~CombustibleBox()
{

}
