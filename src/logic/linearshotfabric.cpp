#include "linearshotfabric.h"
#include "linearshot.h"

LinearShotFabric::LinearShotFabric(int pMaxMunition):ShotFabric(pMaxMunition)
{

}

Shot *LinearShotFabric::getNewShoot(int pX, int pY, bool pPlayer, int pDamage)
{
    if (this->_CurrentMunition > 0){
        return new LinearShot(QRect(pX,pY,Shot::WIDTH_SHOT,Shot::HEIGHT_SHOT),pPlayer,pDamage);
    }
    return 0;

}

LinearShotFabric::~LinearShotFabric()
{

}
