#include "rocket.h"
#include "hpentity.h"

Rocket::Rocket(int pMaxHp) : HPEntity(pMaxHp), _Vx(0), _Vy(0)
{
}

void Rocket::update()
{
    moveInPlace(_Vx,_Vy);
}

void Rocket::setXVelocity(int pXVelocity)
{
    _Vx = pXVelocity;
}

void Rocket::setYVelocity(int pYVelocity)
{
    _Vy = pYVelocity;
}

Rocket::~Rocket(){
}
