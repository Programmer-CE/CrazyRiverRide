#include "gameobject.h"
#include "hpentity.h"
#ifndef SHOT_H
#define SHOT_H
class Shot: public GameObject
{
protected:
    int _Damage;
public:
    static const int VELOCITY;
    static const int ANGLE_SHOT;
    static const int LINEAR_SHOT;
    static const int MAYHEM_SHOT;
    static const int WIDTH_SHOT;
    static const int HEIGHT_SHOT;
    static const int ENEMY_DAMAGE;
    static const bool SHOT_TO_UP;
    static const bool SHOT_TO_DOWN;

    Shot(QRect pRectangle, int pDamage);
    void damage(HPEntity *pEntity);
    virtual bool isUsefulShot(QRect pArea)=0;
    virtual int getXVelocity()=0;
    virtual int getYVelocity()=0;
    virtual int getType()=0;
    virtual ~Shot(){}
};
#endif // SHOT_H
