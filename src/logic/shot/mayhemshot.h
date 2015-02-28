#include "logic/shot/linearshot.h"
#ifndef MAYHEMSHOT_H
#define MAYHEMSHOT_H

class MayhemShot:public LinearShot
{
public:
    MayhemShot(QRect pRectangle, int pDamage);
    void damage(HPEntity *pEntity);
    int getType();
    ~MayhemShot(){}
};

#endif // MAYHEMSHOT_H
