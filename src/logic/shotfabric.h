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
    virtual Shot* getNewShoot(int pX,int pY, bool pPlayer) = 0;
    void addMunition(int pMunition);
    bool haveMunition();
};

#endif // SHOTFABRIC_H
