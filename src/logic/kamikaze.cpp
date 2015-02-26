#include "kamikaze.h"

Kamikaze::Kamikaze(QRect pRectangle, int pMaxHp,Player * pPlayerToFollow):EnemyRocket(pRectangle, pMaxHp)
{
    _PlayerToFollow = pPlayerToFollow;
}

int Kamikaze::getEnemyType()
{
    return Kamikaze::KAMIKAZE;
}

void Kamikaze::update()
{
    if(_PlayerToFollow && !_PlayerToFollow->isDead()){
        int velx = (getX()-_PlayerToFollow->getRocket()->getX())%(ROCKET_VELOCITY-3);
        int vely = (getY()-_PlayerToFollow->getRocket()->getY())%(ROCKET_VELOCITY-3);
        moveInPlace(velx,vely);
    }
    else{
        moveInPlace(0,getYVelocity());
    }
}
