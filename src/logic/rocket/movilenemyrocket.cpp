#include "logic/rocket/movilenemyrocket.h"

MovilEnemyRocket::MovilEnemyRocket(QRect pRectangle, int pMaxHp):EnemyRocket(pRectangle,pMaxHp)
{
}

int MovilEnemyRocket::getEnemyType()
{
    return MovilEnemyRocket::MOVIL_ENEMY_ROCKET;
}

void MovilEnemyRocket::update()
{
    moveInPlace(getXVelocity(),getYVelocity());
}
