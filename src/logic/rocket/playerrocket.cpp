#include "logic/rocket/playerrocket.h"


const int PlayerRocket::COMBUSTIBLE = 100;

const int PlayerRocket::SLEEP_TIME_TO_DECREASE_COMBUSTIBLE = 24;


PlayerRocket::PlayerRocket(QRect pRectangle, int pMaxHp):Rocket(pRectangle,pMaxHp),_Combustible(COMBUSTIBLE),
    _SleepTimeToDecreaseCombustible(0)
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

void PlayerRocket::addCombustible(int pCombustuble)
{
    if (pCombustuble+_Combustible <= 0)_Combustible = 0;
    else if (pCombustuble+_Combustible > COMBUSTIBLE)_Combustible = COMBUSTIBLE;
    else _Combustible += pCombustuble;
}

int PlayerRocket::getCombustible()
{
    return _Combustible;
}

int PlayerRocket::getMunitions()
{
    return _ShotManager->getMunition();
}

int PlayerRocket::getMunitionType()
{
    return _ShotManager->getMunitionType();
}

void PlayerRocket::update()
{
    if (_SleepTimeToDecreaseCombustible++ > SLEEP_TIME_TO_DECREASE_COMBUSTIBLE){
        _SleepTimeToDecreaseCombustible = 0;
        if (_Combustible > 0)_Combustible--;
    }
    Rocket::update();
}

Shot *PlayerRocket::shoot()
{
    return _ShotManager->createMunition(getX()+getWidth()/2, getY());
}

PlayerRocket::~PlayerRocket()
{
    delete _ShotManager;
}
