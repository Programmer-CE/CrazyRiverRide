#include "gameobject.h"
#include "playerrocket.h"
#include "shot.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    PlayerRocket *_Rocket;
    int _StunTime;
    int _Points;
    int _PlayerNumber;
public:
    Player(int pX,int pY,int pPlayerNumber);
    PlayerRocket *getRocket();
    void addPoints(int pPoints);
    int getPoints();
    bool isDead();
    bool revive();
    void update();
    virtual ~Player();
};

#endif // PLAYER_H
