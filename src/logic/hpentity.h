#include "gameobject.h"
#ifndef HPENTITY_H
#define HPENTITY_H

class HPEntity:public GameObject
{
protected:
    int _Hp;
    int _MaxHp;
public:
    HPEntity(QRect pRectangle, int pMaxHp);
    //HPEntity(HPEntity&);
    bool isDead()const;
    void addHitPoints(int pHp = -1);
    int getHitPoints()const;
    virtual ~HPEntity();
};

#endif // HPENTITY_H
