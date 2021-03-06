#include "logic/rocket/enemyrocket.h"
#include "logic/shot/linearshot.h"


const int EnemyRocket::MOVIL_ENEMY_ROCKET = 0;
const int EnemyRocket::KAMIKAZE= 1;


EnemyRocket::EnemyRocket(QRect pRectangle, int pMaxHp):Rocket(pRectangle,pMaxHp)
{
}

Shot *EnemyRocket::shoot()
{
    return new LinearShot(QRect(_Rectangle.center().x(),getY(),Shot::WIDTH_SHOT,Shot::HEIGHT_SHOT),Shot::SHOT_TO_DOWN,Shot::ENEMY_DAMAGE);
}

EnemyRocket::~EnemyRocket()
{

}
