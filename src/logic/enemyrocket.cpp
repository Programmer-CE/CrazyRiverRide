#include "enemyrocket.h"
#include "linearshot.h"

EnemyRocket::EnemyRocket(QRect pRectangle, int pMaxHp):Rocket(pRectangle,pMaxHp)
{
}

Shot *EnemyRocket::shoot()
{
    return new LinearShot(QRect(_Rectangle.center().x(),getY(),Shot::WIDTH_SHOT,Shot::HEIGHT_SHOT),Shot::SHOT_TO_DOWN,Shot::ENEMY_DAMAGE);
}
