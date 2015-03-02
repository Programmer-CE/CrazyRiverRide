#include "list/List.h"
#include "rocket/enemyrocket.h"
#include "patterdesing/subject.h"
#include "patterdesing/observer.h"
#include "protobufmessage/ControlPlayer.pb.h"
#include "player.h"
#include "mapobjects/gamemap.h"
#include "logic/mapobjects/amountbox.h"
#include "logic/mapobjects/combustiblebox.h"
#include "logic/mapobjects/box.h"
#ifndef KERNELGAME_H
#define KERNELGAME_H

class KernelGame:public Subject
{
private:
    int _PlayerPause;
    int _NumOfPlayer;
    bool _Paused,_isRunning;
    int _CurrentTimeToRegenerateEnemies;
    bool _OnMenu,_OnGameTime,_OnBossTime,_OnGameOverTime;
    QRect _Rec;
    GameMap _Map;
    List<EnemyRocket*> _Enemies;
    List<Player*> _Players;
    List<Shot*> _EnemiesShots;
    List<QRect> _SelectionMenu;
    CombustibleBox *_CombustibleBox;
    Box *_HpBox;
    AmountBox *_AmountBox;
    Observer * _UiDriver;
    int _CurrentTimeToBadBox;
    int _CurrentTimeToRegenerateHpBox;
    int _SelectedMenuBotton;
    //List<Box> _Boxes;


    void collisionPlayerWithEnemies(Player *pPlayer);
    void collisionPlayerShotsWithEnemies(Player *pPlayer);
    void collisionPlayerWithBridge(Player *pPlayer);
    void collisionPlayerShotsWithBridge(Player *pPlayer);
    void collisionPlayerWithBox(Player *pPlayer);
    void collisionPlayerShotWithBox(Player *pPlayer);
    void collisionPlayerShotWithBox(Player *pPlayer,Box **pBox);
    void collisionPlayerWithEnemiesShots(Player *pPlayer);
    void changePlayerXVelocity(Player *pPlayer,int pXvelocity);
    void changePlayerYVelocity(Player *pPlayer,int pYvelocity);
    void selectMap(int pMap);
    void stunPlayers(Player *pPlayer);
    void shoot(Player *pPlayer);
    void play(Player *pPlayer);
    bool isStageClear();
    void killPlayer(Player *pPlayer);
    void createPlayer();
    void addRandomEnemy(QRect rec);
    Player *getPlayer(int pPlayerNum);
    void updatePlayers(QRect rec);
    void updateEnemies(QRect rec);
    void randomBoxes(QRect rec);
    void updateBoxes(QRect rec);
    bool allPlayerasDead();
    void inPlayTimeNotify();
public:
    static const int FPS;
    static const int POINTS_PER_ENEMY;
    static const int STUN_TIME;
    static const int TIME_TO_REGENERATE_ENEMIES;
    static const int MAX_ENEMIES_PER_CYCLES;
    static const int TIME_TO_REGENERATE_HPBOXES;
    static const int TIME_TO_BAD_HPBOX;
    static const int ANY_BOX_HEIGHT;
    static const int ANY_BOX_WIDTH;
    KernelGame(QRect rec);
    void update(QRect rec);
    QRect getPlayerRect(int pPlayerNum);
    QRect getRect(){return _Rec;}
    void setObserver(Observer *observer);
    void updateGameData(int pPlayer,int vX,int vY,bool pShoot, bool pPause,bool pChangeMunition);
    bool isRunning();
    void stop();
    void pauseGame();
    bool isPaused();
    void notifyAll();
    //void setKeyYaxis(int pPlayer,int pKeyAxis);
    //void setKeyXaxis(int pPlayer,int pKeyAxis);


    //retorna el tipo de enemigo creado, el tipo puede ser EnemyRocket::MOVIL_ENEMY_ROCKET
    // o puede ser EnemyRocket::KAMIKAZE
    virtual ~KernelGame();

};

#endif // KERNELGAME_H
