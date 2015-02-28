#include "rocket.h"
#include "logic/mapobjects/hpentity.h"

const int Rocket::ROCKET_WIDTH = 128;
const int Rocket::ROCKET_HEIGHT = 108;
const int Rocket::MAX_HP= 100;

const int Rocket::ROCKET_VELOCITY = 15;

Rocket::Rocket(QRect pRectangle, int pMaxHp) : HPEntity(pRectangle,pMaxHp), _Vx(0), _Vy(0)
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

int Rocket::getXVelocity() const
{
    return _Vx;
}

int Rocket::getYVelocity() const
{
    return _Vy;
}

Rocket::~Rocket(){
}
