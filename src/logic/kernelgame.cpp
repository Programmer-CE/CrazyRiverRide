#include "kernelgame.h"
#include "movilenemyrocket.h"
#include "kamikaze.h"
#include <cmath>
const int KernelGame::FPS = 24;
const int KernelGame::POINTS_PER_ENEMY = 50;
const int KernelGame::MAX_ENEMIES_PER_CYCLES = 9;

//tiempo de stuneo cinco segundos
const int KernelGame::STUN_TIME= 5;

const int KernelGame::TIME_TO_REGENERATE_ENEMIES = KernelGame::FPS*10;

void KernelGame::collisionPlayerWithEnemies(Player *pPlayer)
{
    PlayerRocket *rocket = pPlayer->getRocket();
    for (int x= 0; x < this->_Enemies.getLenght();x++){
        if (rocket->isCollide(_Enemies.get(x))){
            rocket->addHitPoints(Shot::ENEMY_DAMAGE);
            delete _Enemies.get(x);
            _Enemies.remove(x);
            break;
        }
    }
}

void KernelGame::collisionPlayerShotsWithEnemies(Player *pPlayer)
{
    List<Shot*> * shotlist = pPlayer->getPlayerShots();
    for (int x= 0; x < shotlist->getLenght();x++){
        for (int y = 0; x < _Enemies.getLenght();y++){
            if (shotlist->get(x)->isCollide(_EnemiesShots.get(x))){
                shotlist->get(x)->damage(_Enemies.get(x));
                if (_Enemies.get(x)->isDead()){
                    pPlayer->addPoints(POINTS_PER_ENEMY);
                    delete _EnemiesShots.get(x);
                    _EnemiesShots.remove(x);
                }
                break;
            }
        }
    }
}

void KernelGame::collisionPlayerWithEnemiesShots(Player *pPlayer)
{
    PlayerRocket *rocket = pPlayer->getRocket();
    for (int x= 0; x < this->_EnemiesShots.getLenght();x++){
        if (rocket->isCollide(_EnemiesShots.get(x))){
            _EnemiesShots.get(x)->damage(rocket);
            delete _EnemiesShots.get(x);
            _EnemiesShots.remove(x);
            break;
        }
    }
}

void KernelGame::addRandomEnemy(QRect rec)
{
    //agrega un enemigo
    //inconcluso
    int typeOfEnemy = rand() %2;
    Player *player = (_Players.get(rand()%_Players.getLenght()));
    int posX = rand() % rec.width();
    QRect enemyPos(posX,0,Rocket::ROCKET_WIDTH,Rocket::ROCKET_HEIGHT);
    if(typeOfEnemy == EnemyRocket::MOVIL_ENEMY_ROCKET)_Enemies.add(new MovilEnemyRocket(enemyPos,Rocket::MAX_HP));
    else _Enemies.add(new Kamikaze(enemyPos,Rocket::MAX_HP,player));
}

KernelGame::KernelGame(QRect rec):_NumOfPlayer(0),_Paused(false){
    _Rec = rec;
    _Paused = false;
    _Players.add(new Player(_Rec.center().x(),_Rec.center().y(),_NumOfPlayer++));
}

void KernelGame::update(QRect rec)
{
    if(!isPaused()){
        Player * player;
        for (int x = 0; x < _Players.getLenght();x++){
            player = _Players.get(x);
            if (!player->isDead()){
                collisionPlayerShotsWithEnemies(player);
                collisionPlayerWithEnemiesShots(player);
                collisionPlayerWithEnemiesShots(player);
                player->update(rec);
            }
        }
        for (int x = 0; x < _Enemies.getLenght();x++){
            if (!_Enemies.get(x)->getRect().intersects(rec)){
                delete _Enemies.get(x);
                _Enemies.remove(x);
                break;
            }
        }
        for (int x = 0; x < _EnemiesShots.getLenght();x++){
            if (!_EnemiesShots.get(x)->getRect().intersects(rec)){
                delete _EnemiesShots.get(x);
                _EnemiesShots.remove(x);
                break;
            }
        }
        addRandomEnemy(rec);
    }
}

void KernelGame::changePlayerXVelocity(Player *pPlayer,int pXvelocity)
{
    pPlayer->getRocket()->setXVelocity(pXvelocity);
}

void KernelGame::changePlayerYVelocity(Player *pPlayer,int pYvelocity)
{
    pPlayer->getRocket()->setYVelocity(pYvelocity);
}

void KernelGame::stunPlayers(Player *pPlayer)
{
    for (int p = 0; p < _Players.getLenght();p++){
        if (pPlayer != _Players.get(p)){
            _Players.get(p)->setStunTime(STUN_TIME*POINTS_PER_ENEMY);
        }
    }
}

void KernelGame::shoot(Player *pPlayer)
{
    pPlayer->shoot();
}

void KernelGame::pause()
{
    _Paused = true;
}

void KernelGame::play(Player *pPlayer){
    if (pPlayer->getPlayerNumber() == 1 || pPlayer->getPlayerNumber() == _PlayerPause)_Paused = true;
}

bool KernelGame::isPaused()
{
    return _Paused;
}

void KernelGame::killPlayer(Player *pPlayer)
{
    pPlayer->getRocket()->addHitPoints(pPlayer->getRocket()->getHitPoints());
    List<Shot*> *shots = pPlayer->getPlayerShots();
    while(!shots->isEmpty()){
        delete shots->get(0);
        shots->remove(0);
    }
}

Player *KernelGame::getPlayer(int pPlayerNum)
{
    for (int x = 0; x < _Players.getLenght();x++){
        if(pPlayerNum == _Players.get(x)->getPlayerNumber())return _Players.get(x);
    }
    return 0;
}


void KernelGame::createPlayer()
{
    _NumOfPlayer++;
    _Players.add(new Player(0,0,_NumOfPlayer));
}



KernelGame::~KernelGame()
{
    for(int x = 0; x < _Enemies.getLenght(); x++)delete _Enemies.get(x);
    for(int x = 0; x < _Players.getLenght(); x++)delete _Players.get(x);
    for(int x = 0; x < _EnemiesShots.getLenght(); x++)delete _EnemiesShots.get(x);

}
