#include "logic/rocket/kamikaze.h"

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
        int velx = (getX() - _PlayerToFollow->getRocket()->getX());
        int vely = (getY() -_PlayerToFollow->getRocket()->getY());

        if (velx >0)velx = -(ROCKET_VELOCITY-9);
        else if(velx == 0) velx = 0;
        else velx= (ROCKET_VELOCITY-9);
        if (vely >0)vely = -(ROCKET_VELOCITY-9);
        else if(vely == 0) vely = 0;
        else vely = (ROCKET_VELOCITY-9);
        moveInPlace(velx,vely);
    }
    else{
        moveInPlace(0,ROCKET_VELOCITY);
    }
}
