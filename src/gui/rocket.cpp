#include "rocket.h"
#include "hpentity.h"

Rocket::Rocket(int pMaxHp):_Vx(0),_Vy(0),HPEntity(pMaxHp)
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

void Rocket::render(QPainter *pPainter)
{
    pPainter->drawPixmap(this->_Rectangle,*_Sprite);
}


Rocket::~Rocket(){
    _Sprite=0;
}
