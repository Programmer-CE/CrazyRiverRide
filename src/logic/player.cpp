#include "player.h"
#include "iostream"


Player::Player(int pX, int pY,int pPlayerNumber):_StunTime(0),_Points(0),_PlayerNumber(pPlayerNumber)
{
    _PlayerShots = new List<Shot*>();
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

int Player::getPlayerNumber() const
{
    return this->_PlayerNumber;
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

void Player::shoot()
{
    /**
    Shot* shot = _Rocket->shoot();
    if (shot->getType() = Shot::ANGLE_SHOT)
    _PlayerShots.add(shot);
    agrega un disparo, revisar para difusion shot;
    **/
}

void Player::setStunTime(int pStunTime)
{
    if(pStunTime > 0)_StunTime = pStunTime;
}

void Player::update(QRect rec)
{
    for (int x = 0; x < _PlayerShots->getLenght();x++){
        if(!_PlayerShots->get(x)->isUsefulShot(rec)){
            delete _PlayerShots->get(x);
            _PlayerShots->remove(x);
            break;
        }
    }
    if (_StunTime ==0){
        int xposition = _Rocket->getX()+_Rocket->getXVelocity();
        if (rec.x() > xposition || xposition > rec.right()) _Rocket->setXVelocity(0);
        int yposition = _Rocket->getY()+_Rocket->getYVelocity();
        if (rec.y() > yposition || yposition > rec.bottom()){
            _Rocket->setYVelocity(0);
        }
        _Rocket->update();
        return;
    }
    _StunTime--;
}

bool Player::operator <(Player const &toCompare){
    return getPlayerNumber() < toCompare.getPlayerNumber();
}
bool Player::operator >(Player const &toCompare){
    return getPlayerNumber() > toCompare.getPlayerNumber();
}

bool Player::operator !=(Player const &toCompare){
    return getPlayerNumber() != toCompare.getPlayerNumber();
}


bool Player::operator ==(Player const &toCompare){
    return getPlayerNumber() == toCompare.getPlayerNumber();
}
/**
bool Player::operator !=(Player const &toCompare){
    return getPlayerNumber() > toCompare.getPlayerNumber();
}

**/

Player::~Player()
{
    for (int x =0 ; x < _PlayerShots->getLenght(); x++){
        delete _PlayerShots->get(x);
    }
    delete _PlayerShots;
    delete _Rocket;
}

List<Shot *> *Player::getPlayerShots()
{
    return _PlayerShots;
}
