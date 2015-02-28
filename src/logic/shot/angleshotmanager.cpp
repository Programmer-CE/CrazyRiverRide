#include "angleshotmanager.h"
#include "logic/shot/angleshot.h"

AngleShotManager::AngleShotManager(int pMaxMunition):ShotFabric(pMaxMunition),current(0)
{
    anglelist= new int[5];
    anglelist[0] = 18;
    anglelist[1] = 54;
    anglelist[2] = 90;
    anglelist[3] = 126;
    anglelist[4] = 162;

}

Shot *AngleShotManager::getNewShoot(int pX, int pY, bool)
{
    if(_CurrentMunition >0){
        _CurrentMunition--;
        return new AngleShot(QRect(pX,pY,Shot::WIDTH_SHOT,Shot::HEIGHT_SHOT),Shot::ANGULAR_DAMAGE,anglelist[current++%5]);
    }
    else return 0;
}

int AngleShotManager::getMunitionType()
{
    return Shot::ANGLE_SHOT;
}

AngleShotManager::~AngleShotManager(){
    delete anglelist;
}
