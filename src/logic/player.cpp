#include "player.h"
#include "iostream"


Player::Player(int pX, int pY,int pPlayerNumber):_StunTime(0),_Points(0),_PlayerNumber(pPlayerNumber),shotcounter(12),_ChangeAmmount(0)
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

void Player::changeMunition()
{
    std::cout << "changeMuntion: " << _ChangeAmmount << std::endl;
    if(_ChangeAmmount == 0){
        _ChangeAmmount = 4;
        _Rocket->nextMunition();
    }
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
    if (shotcounter-- == 0){
        shotcounter = 7;
        Shot* shot = _Rocket->shoot();
        if (shot){
            _PlayerShots->add(shot);
            if (shot->getType() == Shot::ANGLE_SHOT){
                for (int x =0;x <4 ;x++){
                    shot = _Rocket->shoot();
                    if (!shot)break;
                    _PlayerShots->add(shot);
                    _Rocket->addMunition(1);
                }
            }
        }
    }
    //agrega un disparo, revisar para difusion shot;
}

void Player::setStunTime(int pStunTime)
{
    if(pStunTime > 0)_StunTime = pStunTime;
}

void Player::update(QRect rec)
{
    if (_ChangeAmmount > 0)_ChangeAmmount--;
    if (_StunTime ==0){
        int xposition = _Rocket->getX()+_Rocket->getXVelocity();
        int yposition = _Rocket->getY()+_Rocket->getYVelocity();
        if (rec.x() > xposition || xposition+_Rocket->getWidth() > rec.right()) _Rocket->setXVelocity(0);
        if (rec.y() > yposition || yposition+_Rocket->getHeight() > rec.bottom()){
            _Rocket->setYVelocity(0);
        }
        _Rocket->update();
        for (int x = 0; x < _PlayerShots->getLenght();x++){
            if(!_PlayerShots->get(x)->isUsefulShot(rec)){
                delete _PlayerShots->get(x);
                _PlayerShots->remove(x);
                break;
            }
        }

        for (int y = 0; y < _PlayerShots->getLenght();y++){
            _PlayerShots->get(y)->update();
        }
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
