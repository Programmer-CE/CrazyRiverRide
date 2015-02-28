#include "logic/shot/shotfabric.h"
#ifndef MAYHEMSHOTMANAGER_H
#define MAYHEMSHOTMANAGER_H

class MayhemShotManager:public ShotFabric
{
public:
    MayhemShotManager(int pMaxMunition);
    int getMunitionType();
    Shot *getNewShoot(int pX,int pY, bool pPlayer);
};

#endif // MAYHEMSHOTMANAGER_H
