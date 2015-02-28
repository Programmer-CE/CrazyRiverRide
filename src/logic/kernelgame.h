#include "list/List.h"
#include "rocket/enemyrocket.h"
#include "patterdesing/subject.h"
#include "patterdesing/observer.h"
#include "protobufmessage/ControlPlayer.pb.h"
#include "player.h"
#include "mapobjects/gamemap.h"
#ifndef KERNELGAME_H
#define KERNELGAME_H

class KernelGame:public Subject
{
private:
    int _PlayerPause;
    int _NumOfPlayer;
    bool _Paused,_isRunning;
    int _CurrentTimeToRegenerateEnemies;
    bool _OnMenu;
    QRect _Rec;
    GameMap _Map;
    List<EnemyRocket*> _Enemies;
    List<Player*> _Players;
    List<Shot*> _EnemiesShots;
    Observer * _UiDriver;
    //List<Box> _Boxes;


    void collisionPlayerWithEnemies(Player *pPlayer);
    void collisionPlayerShotsWithEnemies(Player *pPlayer);
    void collisionPlayerWithBridge(Player *pPlayer);
    void collisionPlayerShotsWithBridge(Player *pPlayer);
    //void collisionPlayerWithEnemies(Player *pPlayer);
    void collisionPlayerWithEnemiesShots(Player *pPlayer);
    void changePlayerXVelocity(Player *pPlayer,int pXvelocity);
    void changePlayerYVelocity(Player *pPlayer,int pYvelocity);
    void selectMap(int pMap);
    void stunPlayers(Player *pPlayer);
    void shoot(Player *pPlayer);
    void pause();
    void play(Player *pPlayer);
    bool isPaused();
    bool isStageClear();
    void killPlayer(Player *pPlayer);
    void createPlayer();
    void addRandomEnemy(QRect rec);
    Player *getPlayer(int pPlayerNum);
    void updatePlayers(QRect rec);
    void updateEnemies(QRect rec);
public:
    static const int FPS;
    static const int POINTS_PER_ENEMY;
    static const int STUN_TIME;
    static const int TIME_TO_REGENERATE_ENEMIES;
    static const int MAX_ENEMIES_PER_CYCLES;
    KernelGame(QRect rec);
    void update(QRect rec);
    QRect getPlayerRect(int pPlayerNum);
    QRect getRect(){return _Rec;}
    void setObserver(Observer *observer);
    void updatePlayerPosition(int pPlayer,int vX,int vY,bool pShoot, bool pPause);
    bool isRunning();
    void stop();
    void notifyAll();
    //void setKeyYaxis(int pPlayer,int pKeyAxis);
    //void setKeyXaxis(int pPlayer,int pKeyAxis);


    //retorna el tipo de enemigo creado, el tipo puede ser EnemyRocket::MOVIL_ENEMY_ROCKET
    // o puede ser EnemyRocket::KAMIKAZE
    virtual ~KernelGame();

};

#endif // KERNELGAME_H
