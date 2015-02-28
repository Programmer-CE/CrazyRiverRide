#include "mayhemshotmanager.h"
#include "logic/shot/mayhemshot.h"

MayhemShotManager::MayhemShotManager(int pMaxMunition):ShotFabric(pMaxMunition)
{
}

int MayhemShotManager::getMunitionType()
{
    return Shot::MAYHEM_SHOT;
}

Shot *MayhemShotManager::getNewShoot(int pX, int pY, bool)
{
    if (this->_CurrentMunition > 0){
        _CurrentMunition--;
        return new MayhemShot(QRect(pX,pY,Shot::WIDTH_SHOT,Shot::HEIGHT_SHOT),Shot::LINEAR_DAMAGE);
    }
    return 0;
}
