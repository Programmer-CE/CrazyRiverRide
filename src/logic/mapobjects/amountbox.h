#include "box.h"
#ifndef AMOUNTBOX_H
#define AMOUNTBOX_H

class AmountBox:public Box
{
public:
    AmountBox(QRect pRect, int pMaxHp,int pPointsToAdd);
    void addPointsToPlayer(Player *pPlayer);
    virtual ~AmountBox();
};

#endif // AMOUNTBOX_H
