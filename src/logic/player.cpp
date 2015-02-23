#include "player.h"

Player::Player(int pX, int pY,int pPlayerNumber):_StunTime(0),_Points(0),_PlayerNumber(pPlayerNumber)
{
    _Rocket = new PlayerRocket(QRect(pX,pY,Rocket::ROCKET_WIDTH,Rocket::ROCKET_HEIGHT),Rocket::MAX_HP);
}

PlayerRocket *Player::getRocket()
{
    return _Rocket;
}

void Player::addPoints(int pPoints)
{
    _Points+=pPoints;
}

int Player::getPoints()
{
    return _Points;
}

bool Player::isDead()
{
    return _Rocket->isDead();
}

bool Player::revive()
{
    if (_Points > 0){
        _PlayerNumber /=2;
        return true;
    }
    return false;
}

void Player::update()
{
    if (_StunTime ==0){
        _Rocket->update();
        return;
    }
    _StunTime--;
}

Player::~Player()
{
    delete _Rocket;
}
