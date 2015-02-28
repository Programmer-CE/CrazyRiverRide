#include "mayhemshot.h"


MayhemShot::MayhemShot(QRect pRectangle, int pDamage):LinearShot(pRectangle,true,pDamage)
{
}

void MayhemShot::damage(HPEntity *pEntity)
{
    pEntity->addHitPoints(-pEntity->getHitPoints());
}

int MayhemShot::getType()
{
    return Shot::MAYHEM_SHOT;
}
