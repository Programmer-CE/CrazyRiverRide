#include "shotfabric.h"

ShotFabric::ShotFabric(int pMaxMunition):_MaxMunition(pMaxMunition),_CurrentMunition(pMaxMunition)
{

}
void ShotFabric::addMunition(int pMunition){
    if (_CurrentMunition+pMunition <= 0)_CurrentMunition = 0;
    else if (_CurrentMunition+pMunition > _MaxMunition) _CurrentMunition = _MaxMunition;
    else _CurrentMunition += pMunition;
}


bool ShotFabric::haveMunition(){
    return _CurrentMunition == 0;
}

ShotFabric::~ShotFabric()
{

}
