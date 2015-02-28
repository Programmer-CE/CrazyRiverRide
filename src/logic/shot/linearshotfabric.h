#include "shotfabric.h"
#ifndef LINEARSHOTFABRIC_H
#define LINEARSHOTFABRIC_H

class LinearShotFabric:public ShotFabric
{
public:
    LinearShotFabric(int pMaxMunition);
    Shot* getNewShoot(int pX,int pY, bool pPlayer);
    virtual ~LinearShotFabric();
};

#endif // LINEARSHOTFABRIC_H
