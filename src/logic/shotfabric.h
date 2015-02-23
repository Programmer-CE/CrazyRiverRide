#include "shot.h"
#ifndef SHOTFABRIC_H
#define SHOTFABRIC_H

class ShotFabric
{
protected:
    // es la cantidad de municion que tiene el jugador.
    int _CurrentMunition;
    //Es la cantidad maxima de municiones que tiene e jugador.
    int _MaxMunition;


public:
    ShotFabric(int pMaxMunition);
    virtual Shot* getNewShoot(int pX,int pY, bool pPlayer,int pDamage) = 0;
    void addMunition(int pMunition);
    bool haveMunition();
    virtual ~ShotFabric();
};

#endif // SHOTFABRIC_H
