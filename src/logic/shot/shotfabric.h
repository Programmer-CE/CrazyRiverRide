#include "shot.h"
#ifndef SHOTFABRIC_H
#define SHOTFABRIC_H

class ShotFabric
{

protected:
    //Es la cantidad maxima de municiones que tiene e jugador.
    int _MaxMunition;
    // es la cantidad de municion que tiene el jugador.
    int _CurrentMunition;


public:
    ShotFabric(int pMaxMunition);
    virtual Shot* getNewShoot(int pX,int pY, bool pPlayer) = 0;
    void addMunition(int pMunition);
    bool haveMunition();
    int getMunitions();
    virtual int getMunitionType() = 0;
    virtual ~ShotFabric();
};

#endif // SHOTFABRIC_H
