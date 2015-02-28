#include "shotfabric.h"
#ifndef ANGLESHOTMANAGER_H
#define ANGLESHOTMANAGER_H

class AngleShotManager:public ShotFabric
{
    int * anglelist;
    int current;
public:
    AngleShotManager(int pMaxMunition);
    Shot *getNewShoot(int pX,int pY, bool pPlayer);
    int getMunitionType();
    virtual ~AngleShotManager();
};

#endif // ANGLESHOTMANAGER_H
