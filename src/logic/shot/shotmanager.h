#include "list/CircularList.h"
#include "list/IIterator.h"
#include "logic/shot/shotfabric.h"

#ifndef SHOTMANAGER_H
#define SHOTMANAGER_H

class ShotManager    
{

    static const int LINEAR_MUNITION;
    static const int DIFUSION_MUNITION;
    static const int MAYHEM_MUNITION;


    CircularList<ShotFabric*> _ShotFabric;
    IIterator<ShotFabric*> *_iterator;
public:
    ShotManager();
    Shot* createMunition(int pX,int pY);
    void nextMunition();
    void addMunition(int pMunition);
    int getMunition();
    int getMunitionType();
    virtual ~ShotManager();
};

#endif // SHOTMANAGER_H
