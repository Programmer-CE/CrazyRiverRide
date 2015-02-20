#include "shotfabric.h"

void ShotFabric::addMunition(int pMunition){
    if (_CurrentMunition+pMunition <= 0)_CurrentMunition = 0;
    else if (_CurrentMunition+pMunition > _MaxMunition) _CurrentMunition = _MaxMunition;
    else _CurrentMunition += pMunition;
}


bool ShotFabric::haveMunition(){
    return _CurrentMunition == 0;
}
