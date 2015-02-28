#include "logic/shot/angleshot.h"
#include <cmath>
#include <iostream>
AngleShot::AngleShot(QRect pRectangle, int pDamage, float pAngle):LinearShot(pRectangle,true,pDamage)
{
    if (0 < pAngle && pAngle < 180){ 
        _VelocityX = double(VELOCITY)*cos(pAngle*M_PI/double(180));
        _VelocityY = double(-VELOCITY)*sin(pAngle*M_PI/double(180));
        std::cout << "velocidad x: "<<_VelocityX<< " velocidad y: "<<_VelocityY << std::endl;
    }
    else{
        _VelocityX = 0;
        _VelocityY = 0;
    }
}

void AngleShot::update()
{
    moveInPlace(_VelocityX,_VelocityY);
}

int AngleShot::getType()
{
    return ANGLE_SHOT;
}

int AngleShot::getXVelocity()
{
    return _VelocityX;
}

AngleShot::~AngleShot()
{

}
