#include "linearshot.h"
#ifndef ANGLESHOT_H
#define ANGLESHOT_H

class AngleShot:public LinearShot
{
    float _Angle;
    int _VelocityX;
public:
    AngleShot(QRect pRectangle,int pDamage, float pAngle);
    void update();
    int getType();
    int getXVelocity();
    virtual ~AngleShot();
};

#endif // ANGLESHOT_H
