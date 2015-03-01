#include "amountbox.h"

AmountBox::AmountBox(QRect pRect, int pMaxHp,int pPointsToAdd):Box(pRect,pMaxHp,pPointsToAdd)
{
}

void AmountBox::addPointsToPlayer(Player *pPlayer)
{
    pPlayer->getRocket()->addMunition(_PointsToAdd);
}

AmountBox::~AmountBox()
{

}
