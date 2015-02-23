#include "shotmanager.h"
#include "linearshotfabric.h"

const int ShotManager::LINEAR_MUNITION = 40;
const int ShotManager::DIFUSION_MUNITION = 40;
const int ShotManager::MAYHEM_MUNITION = 40;


ShotManager::ShotManager()
{
    _ShotFabric.add(new LinearShotFabric(LINEAR_MUNITION));
    _iterator = _ShotFabric.getIterator();
}

Shot *ShotManager::createMunition(int pX, int pY)
{
    return _iterator->getCurrent()->getNewShoot(pX,pY,true);
}

void ShotManager::nextMunition()
{
    _iterator->getNext();
}

ShotManager::~ShotManager()
{
    delete _iterator;
    while(!_ShotFabric.isEmpty()){
        delete _ShotFabric.get(0);
        _ShotFabric.set(0,0);
        _ShotFabric.remove(0);
    }
}
