#include "logic/rocket/playerrocket.h"

PlayerRocket::PlayerRocket(QRect pRectangle, int pMaxHp):Rocket(pRectangle,pMaxHp)
{
    _ShotManager = new ShotManager();
}

void PlayerRocket::nextMunition()
{
    _ShotManager->nextMunition();
}

void PlayerRocket::addMunition(int pMunition)
{
    _ShotManager->addMunition(pMunition);
}

int PlayerRocket::getMunitions()
{
    return _ShotManager->getMunition();
}

int PlayerRocket::getMunitionType()
{
    return _ShotManager->getMunitionType();
}

Shot *PlayerRocket::shoot()
{
    return _ShotManager->createMunition(getX()+getWidth()/2, getY());
}

PlayerRocket::~PlayerRocket()
{
    delete _ShotManager;
}
