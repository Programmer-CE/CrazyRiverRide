#include "shot.h"

const int Shot::VELOCITY = 10;
const int Shot::LINEAR_SHOT = 1;
const int Shot::ANGLE_SHOT = 2;
const int Shot::MAYHEM_SHOT = 3;
const int Shot::WIDTH_SHOT = 32;
const int Shot::HEIGHT_SHOT = 32;

const bool Shot::SHOT_TO_UP = true;
const bool Shot::SHOT_TO_DOWN = false;


Shot::Shot(QRect pRectangle, int pDamage):GameObject(pRectangle)
{
    _Damage = pDamage;
}

void Shot::damage(HPEntity *pEntity){
    pEntity->addHitPoints(_Damage);
}
