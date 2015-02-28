#include "logic/shot/linearshotfabric.h"
#include "logic/shot/linearshot.h"

LinearShotFabric::LinearShotFabric(int pMaxMunition):ShotFabric(pMaxMunition)
{

}


Shot *LinearShotFabric::getNewShoot(int pX, int pY, bool pPlayer)
{
    if (this->_CurrentMunition > 0){
        return new LinearShot(QRect(pX,pY,Shot::WIDTH_SHOT,Shot::HEIGHT_SHOT),pPlayer,Shot::LINEAR_DAMAGE);
    }
    return 0;

}

LinearShotFabric::~LinearShotFabric()
{

}
