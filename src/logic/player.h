#include "logic/mapobjects/gameobject.h"
#include "logic/rocket/playerrocket.h"
#include "logic/shot/shot.h"
#include "list/List.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    PlayerRocket *_Rocket;
    int _StunTime;
    int _Points;
    int _PlayerNumber;
    int shotcounter;
    int _ChangeAmmount;
    List<Shot *> *_PlayerShots;
public:
    Player(int pX,int pY,int pPlayerNumber);
    Player(Player&);
    PlayerRocket *getRocket();
    void addPoints(int pPoints);
    int getPoints();
    int getPlayerNumber() const;
    void changeMunition();
    bool isDead();
    bool revive();
    void shoot();
    void setStunTime(int pStunTime);
    void deleteShot(string pId);
    bool operator <(Player const& otherPlayer);
    bool operator >(Player const& otherPlayer);
    bool operator !=(Player const& otherPlayer);
    bool operator ==(Player const& otherPlayer);
    void update(QRect rec);
    virtual ~Player();
    List<Shot *> *getPlayerShots();
};

#endif // PLAYER_H
