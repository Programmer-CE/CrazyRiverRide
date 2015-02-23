#include "playerrocket.h"

PlayerRocket::PlayerRocket(QRect pRectangle, int pMaxHp):Rocket(pRectangle,pMaxHp)
{
    _ShotManager = new ShotManager();
}

void PlayerRocket::nextMunition()
{
    _ShotManager->nextMunition();
}

Shot *PlayerRocket::shoot()
{
    return _ShotManager->createMunition(getX()+getWidth()/2, getY());
}

PlayerRocket::~PlayerRocket()
{
    delete _ShotManager;
}
