#include "shotfabric.h"
#ifndef ANGLESHOTMANAGER_H
#define ANGLESHOTMANAGER_H

class AngleShotManager:public ShotFabric
{
    int *anglelist;
public:
    AngleShotManager(int pMaxMunition);
    Shot* getNewShoot(int pX,int pY, bool pPlayer);
    virtual ~AngleShotManager(){}
};

#endif // ANGLESHOTMANAGER_H
