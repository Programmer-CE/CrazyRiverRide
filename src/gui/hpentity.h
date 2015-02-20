#include "renderizable.h"
#ifndef HPENTITY_H
#define HPENTITY_H

class HPEntity:public Renderizable
{
protected:
    int _Hp;
    int _MaxHp;
public:
    HPEntity(int pMaxHp);
    bool isDead()const;
    void addHitPoints(int pHp = -1);
    int getHitPoints()const;
    virtual ~HPEntity();
};

#endif // HPENTITY_H
