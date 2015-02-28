#include "logic/shot/shotmanager.h"
#include "logic/shot/linearshotfabric.h"
#include "logic/shot/angleshotmanager.h"
#include "logic/shot/mayhemshotmanager.h"

const int ShotManager::LINEAR_MUNITION = 40;
const int ShotManager::DIFUSION_MUNITION = 40;
const int ShotManager::MAYHEM_MUNITION = 40;


ShotManager::ShotManager()
{
    _ShotFabric.add(new LinearShotFabric(LINEAR_MUNITION));
    _ShotFabric.add(new AngleShotManager(DIFUSION_MUNITION));
    _ShotFabric.add(new MayhemShotManager(MAYHEM_MUNITION));
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

void ShotManager::addMunition(int pMunition)
{
    _iterator->getCurrent()->addMunition(pMunition);
}

int ShotManager::getMunition()
{
    return _iterator->getCurrent()->getMunitions();
}

int ShotManager::getMunitionType()
{
    return _iterator->getCurrent()->getMunitionType();
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
