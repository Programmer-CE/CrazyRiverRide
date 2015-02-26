#include "list/List.h"
#include "enemyrocket.h"
#include "player.h"
#ifndef KERNELGAME_H
#define KERNELGAME_H

class KernelGame
{
private:
    bool _Paused;
    int _PlayerPause;
    int _CurrentTimeToRegenerateEnemies;
    bool _OnMenu;
    List<EnemyRocket*> _Enemies;
    List<Player*> _Players;
    List<Shot*> _EnemiesShots;
    //List<Box> _Boxes;


    void collisionPlayerWithEnemies(Player *pPlayer);
    void collisionPlayerShotsWithEnemies(Player *pPlayer);
    void collisionPlayerWithBridge(Player *pPlayer);
    void collisionPlayerShotsWithBridge(Player *pPlayer);
    //void collisionPlayerWithEnemies(Player *pPlayer);
    void collisionPlayerWithEnemiesShots(Player *pPlayer);
    void addRandomEnemy(QRect rec);
public:
    static const int FPS;
    static const int POINTS_PER_ENEMY;
    static const int STUN_TIME;
    static const int TIME_TO_REGENERATE_ENEMIES;
    static const int MAX_ENEMIES_PER_CYCLES;
    KernelGame();
    void update(QRect rec);
    void changePlayerXVelocity(Player *pPlayer,int pXvelocity);
    void changePlayerYVelocity(Player *pPlayer,int pYvelocity);
    void selectMap(int pMap);
    void stunPlayers(Player *pPlayer);
    void shoot(Player *pPlayer);
    void pause();
    void play(Player *pPlayer);
    bool isPaused();
    bool isStageClear();
    Player *getPlayer(int pPlayerNum);

};

#endif // KERNELGAME_H
