#include "kernelgame.h"
#include "logic/rocket/movilenemyrocket.h"
#include "logic/rocket/kamikaze.h"
#include <cmath>
#include <iostream>
#include "protobufmessage/GameObjectNotify.pb.h"
#include "protobufmessage/PlayerStatus.pb.h"
#include "protobufmessage/Pause.pb.h"

const int KernelGame::FPS = 24;
const int KernelGame::POINTS_PER_ENEMY = 50;
const int KernelGame::MAX_ENEMIES_PER_CYCLES = 9;
const int KernelGame::TIME_TO_REGENERATE_HPBOXES =KernelGame::FPS*15;
const int KernelGame::TIME_TO_BAD_HPBOX = 3*KernelGame::FPS;
const int KernelGame::ANY_BOX_HEIGHT = 54;
const int KernelGame::ANY_BOX_WIDTH = 54;


//tiempo de stuneo cinco segundos
const int KernelGame::STUN_TIME= 5;

const int KernelGame::TIME_TO_REGENERATE_ENEMIES = KernelGame::FPS*10;







//==================================================================================================
// 01 CONSTRUCTOR
//==================================================================================================

KernelGame::KernelGame(QRect rec):_NumOfPlayer(0),_Paused(false),_isRunning(true),
    _Map(QRect(rec.x(),-5000+800,1024,5000),2,0),_CurrentTimeToBadBox(0), _CurrentTimeToRegenerateHpBox(0)
{
    _Rec = rec;
    _Players.add(new Player(_Rec.center().x(),_Rec.center().y(),_NumOfPlayer++));
    _AmountBox = 0;
    _CombustibleBox = 0;
    _HpBox = 0;
}

//==================================================================================================
// 01 FIN DE CONSTRUCTOR
//==================================================================================================

















//==================================================================================================
// 02 MANEJO DE COLISIONES
//==================================================================================================

void KernelGame::collisionPlayerWithEnemies(Player *pPlayer)
{
    PlayerRocket *rocket = pPlayer->getRocket();
    for (int x= 0; x < this->_Enemies.getLenght();x++){
        if (rocket->isCollide(_Enemies.get(x))){
            rocket->addHitPoints(Shot::ENEMY_DAMAGE);
            if(rocket->isDead()){
                killPlayer(pPlayer);
            }
            delete _Enemies.get(x);
            _Enemies.remove(x);
            break;
        }
    }
}

void KernelGame::collisionPlayerShotsWithEnemies(Player *pPlayer)
{
    List<Shot*> * shotlist = pPlayer->getPlayerShots();
    Shot* shot = 0;
    for (int x= 0; x < shotlist->getLenght();x++){
        for (int y = 0; y < _Enemies.getLenght();y++){
            shot = shotlist->get(x);
            if (shot->isCollide(_Enemies.get(y))){
                shot->damage(_Enemies.get(y));
                delete shot;
                shotlist->remove(x);
                if (_Enemies.get(y)->isDead()){
                    pPlayer->addPoints(POINTS_PER_ENEMY);
                    delete _Enemies.get(y);
                    _Enemies.remove(y);
                }
                break;
            }
        }
    }
}


void KernelGame::collisionPlayerWithBox(Player *pPlayer)
{
    if (_AmountBox){
        if (_AmountBox->isCollide(pPlayer->getRocket())){
            _AmountBox->addPointsToPlayer(pPlayer);
            delete _AmountBox;
            _AmountBox = 0;
        }
    }
    if (_CombustibleBox){
        if (_CombustibleBox->isCollide(pPlayer->getRocket())){
            _CombustibleBox->addPointsToPlayer(pPlayer);
            delete _CombustibleBox;
            _CombustibleBox = 0;
        }
    }
    if (_HpBox){
        if (_HpBox->isCollide(pPlayer->getRocket())){
            _HpBox->addPointsToPlayer(pPlayer);
            delete _HpBox;
            _HpBox = 0;
        }

    }
}

void KernelGame::collisionPlayerShotWithBox(Player *pPlayer)
{
    if (_AmountBox){
        collisionPlayerShotWithBox(pPlayer,(Box**)&_AmountBox);
    }
    if (_CombustibleBox){
        List<Shot*> *shots = pPlayer->getPlayerShots();
        for(int x = 0; x < shots->getLenght();x++){
            if (shots->get(x)->isCollide(_CombustibleBox)){
                if (!_CombustibleBox->isBadBox())_CombustibleBox->turnAbadBox();
                delete shots->get(x);
                shots->remove(x);
                break;
            }
        }

    }
    if (_HpBox){
        collisionPlayerShotWithBox(pPlayer,&_HpBox);
    }
}

void KernelGame::collisionPlayerShotWithBox(Player *pPlayer, Box **pBox)
{
    List<Shot*> *shots = pPlayer->getPlayerShots();
    for(int x = 0; x < shots->getLenght();x++){
        if (shots->get(x)->isCollide(*pBox)){
            delete *pBox;
            *pBox = 0;
            delete shots->get(x);
            shots->remove(x);
            break;
        }
    }
}

void KernelGame::collisionPlayerWithEnemiesShots(Player *pPlayer)
{
    PlayerRocket *rocket = pPlayer->getRocket();
    for (int x= 0; x < this->_EnemiesShots.getLenght();x++){
        if (rocket->isCollide(_EnemiesShots.get(x))){
            _EnemiesShots.get(x)->damage(rocket);
            if (rocket->isDead())killPlayer(pPlayer);
            delete _EnemiesShots.get(x);
            _EnemiesShots.remove(x);
            break;
        }
    }
}



//==================================================================================================
// 02 FINAL DE MANEJO DE COLISIONES
//==================================================================================================














//==================================================================================================
// 03 AGREGAR ENEMIGOS DE MANERA ALEATORIA
//==================================================================================================

void KernelGame::addRandomEnemy(QRect rec)
{
    //agrega un enemigo
    //inconcluso
    if (_Enemies.getLenght() < 3){
        int typeOfEnemy = rand() %2;
        Player *player = (_Players.get(rand()%_Players.getLenght()));
        int posX = rand() % rec.width();
        QRect enemyPos(posX,0,Rocket::ROCKET_WIDTH,Rocket::ROCKET_HEIGHT);
        if(typeOfEnemy == 0){
            _Enemies.add(new MovilEnemyRocket(enemyPos,Rocket::ENEMY_MAX_HP));
        }
        else{
            _Enemies.add(new Kamikaze(enemyPos,Rocket::ENEMY_MAX_HP,player));
        }
    }
}

//==================================================================================================
// 03 FINAL DE AGREGAR ENEMIGOS DE MANERA ALEATORIA
//==================================================================================================










//==================================================================================================
// 04 ACTUALIZACIONES DEL JUEGO
//==================================================================================================


void KernelGame::update(QRect rec)
{
    if(!isPaused()){
        updatePlayers(rec);
        updateEnemies(rec);
        addRandomEnemy(rec);
        randomBoxes(rec);
        updateBoxes(rec);
        _Map.update();
        notifyAll();
    }
    /**
    std::cout << "cantidad de disparos jugador" << _Players.get(0)->getPlayerShots()->getLenght() << std::endl;
    std::cout << "cantidad de disparos enemigos" << _EnemiesShots.getLenght() << std::endl;
    std::cout << "cantidad de enemigos" << _Enemies.getLenght() << std::endl;
    */
}


void KernelGame::updatePlayers(QRect rec)
{
    Player * player = _Players.get(0);
    for (int x = 0; x < _Players.getLenght();x++){
        player = _Players.get(x);
        if (!player->isDead()){
            player->update(rec);
            collisionPlayerShotsWithEnemies(player);
            collisionPlayerWithEnemiesShots(player);
            collisionPlayerWithEnemies(player);
            collisionPlayerShotWithBox(player);
            collisionPlayerWithBox(player);
        }
    }
}

void KernelGame::updateEnemies(QRect rec)
{
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
    for (int x = 0; x < _Enemies.getLenght();x++){
        if(_Enemies.get(x)->getEnemyType() == EnemyRocket::MOVIL_ENEMY_ROCKET){
            _Enemies.get(x)->setXVelocity(((rand()%3)-1)*Rocket::ROCKET_VELOCITY);
            _Enemies.get(x)->setYVelocity((1)*Rocket::ROCKET_VELOCITY);
        }
        _Enemies.get(x)->update();
    }
}

void KernelGame::randomBoxes(QRect rec)
{

    if (!_AmountBox){
        if (rand()%70 == rand()%70){
            _AmountBox = new AmountBox(QRect(rand()%rec.width(),0,ANY_BOX_WIDTH,ANY_BOX_HEIGHT),1,(rand()%10) +5);
        }

    }
    if (!_CombustibleBox){
        if (rand()%70 == rand()%70){
            _CombustibleBox = new CombustibleBox(QRect(rand()%rec.width(),0,ANY_BOX_WIDTH,ANY_BOX_HEIGHT),1,(rand()%50) +25);
        }
    }
    if (!_HpBox){
        if (_CurrentTimeToRegenerateHpBox++ == TIME_TO_REGENERATE_HPBOXES){
            _CurrentTimeToRegenerateHpBox = 0;
            _HpBox = new Box(QRect(rand()%rec.width(),0,ANY_BOX_WIDTH,ANY_BOX_HEIGHT),1,(rand()%30) +15);
        }
    }
}

void KernelGame::updateBoxes(QRect rec)
{
    if (_AmountBox){
        _AmountBox->update();
        if (!rec.intersects(_AmountBox->getRect())){
            delete _AmountBox;
            _AmountBox = 0;
        }

    }
    if (_HpBox){
        _HpBox->update();
        if(_CurrentTimeToBadBox++ > KernelGame::TIME_TO_BAD_HPBOX){
            _CurrentTimeToBadBox = 0;
            _HpBox->turnAbadBox();
        }
        if (!rec.intersects(_HpBox->getRect())){
            delete _HpBox;
            _HpBox = 0;
        }
    }
    if (_CombustibleBox){
        if (!rec.intersects(_CombustibleBox->getRect())){
            delete _CombustibleBox;
            _CombustibleBox = 0;
        }
        else _CombustibleBox->update();
    }
}


void KernelGame::notifyAll()
{
    GameObjectNotify *message;
    message = new GameObjectNotify();
    message->set_height(_Map.getHeight());
    message->set_width(_Map.getWidth());
    message->set_x(_Map.getX());
    message->set_y(_Map.getY());
    message->set_type(0);
    _UiDriver->update(message);
    delete message;
    for (int x = 0; x < _Players.getLenght();x++){
        message = new GameObjectNotify();
        if(!_Players.get(x)->isDead()){
            message->set_height(_Players.get(x)->getRocket()->getHeight());
            message->set_width(_Players.get(x)->getRocket()->getWidth());
            message->set_x(_Players.get(x)->getRocket()->getX());
            message->set_y(_Players.get(x)->getRocket()->getY());
            message->set_type(1);
            _UiDriver->update(message);
        }


        delete message;
    }
    for (int x = 0; x < _Enemies.getLenght();x++){
        message = new GameObjectNotify();
        message->set_height(_Enemies.get(x)->getHeight());
        message->set_width(_Enemies.get(x)->getWidth());
        message->set_x(_Enemies.get(x)->getX());
        message->set_y(_Enemies.get(x)->getY());
        message->set_type(2);
        _UiDriver->update(message);
        delete message;
    }

    for (int x = 0; x < _EnemiesShots.getLenght();x++){
        message = new GameObjectNotify();
        message->set_height(_EnemiesShots.get(x)->getHeight());
        message->set_width(_EnemiesShots.get(x)->getWidth());
        message->set_x(_EnemiesShots.get(x)->getX());
        message->set_y(_EnemiesShots.get(x)->getY());
        message->set_type(3);
        _UiDriver->update(message);
        delete message;
    }
    for (int x = 0; x < _Players.getLenght();x++){
        for (int y = 0; y < _Players.get(x)->getPlayerShots()->getLenght();y++){
            message = new GameObjectNotify();
            message->set_height(_Players.get(x)->getPlayerShots()->get(y)->getHeight());
            message->set_width(_Players.get(x)->getPlayerShots()->get(y)->getWidth());
            message->set_x(_Players.get(x)->getPlayerShots()->get(y)->getX());
            message->set_y(_Players.get(x)->getPlayerShots()->get(y)->getY());
            message->set_type(4);
            _UiDriver->update(message);
            delete message;
        }
    }
    if (_AmountBox){
        message = new GameObjectNotify();
        message->set_x(_AmountBox->getX());
        message->set_y(_AmountBox->getY());
        message->set_width(_AmountBox->getWidth());
        message->set_height(_AmountBox->getHeight());
        message->set_type(5);
        _UiDriver->update(message);
        delete message;
    }
    if (_CombustibleBox){
        message = new GameObjectNotify();
        message->set_x(_CombustibleBox->getX());
        message->set_y(_CombustibleBox->getY());
        message->set_width(_CombustibleBox->getWidth());
        message->set_height(_CombustibleBox->getHeight());
        if (_CombustibleBox->isBadBox()){
            message->set_type(7);
        }
        else{
            message->set_type(6);
        }
        _UiDriver->update(message);
        delete message;
    }
    if (_HpBox){
        message = new GameObjectNotify();
        message->set_x(_HpBox->getX());
        message->set_y(_HpBox->getY());
        message->set_width(_HpBox->getWidth());
        message->set_height(_HpBox->getHeight());
        if (_HpBox->isBadBox()){
            message->set_type(9);
        }
        else{
            message->set_type(8);
        }
        _UiDriver->update(message);
        delete message;

    }

    PlayerStatus *statusmessage = new PlayerStatus();
    statusmessage->set_playerpoints(_Players.get(0)->getPoints());
    statusmessage->set_num_of_player(0);
    statusmessage->set_isdead(_Players.get(0)->isDead());
    statusmessage->set_playerlife(_Players.get(0)->getRocket()->getHitPoints());
    statusmessage->set_numofmunition(_Players.get(0)->getRocket()->getMunitions());
    statusmessage->set_typeofmunition(_Players.get(0)->getRocket()->getMunitionType());
    statusmessage->set_combustible(_Players.get(0)->getRocket()->getCombustible());
    _UiDriver->update(statusmessage);
    delete statusmessage;

}


//==================================================================================================
// 04 FINAL DE ACTUALIZACIONES DEL JUEGO
//==================================================================================================

















//==================================================================================================
// 05 MANEJO DE JUGADORES
//==================================================================================================

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

QRect KernelGame::getPlayerRect(int pPlayerNum)
{
    return getPlayer(pPlayerNum)->getRocket()->getRect();
}

void KernelGame::setObserver(Observer *observer)
{
    _UiDriver = observer;
}

void KernelGame::updatePlayerPosition(int pPlayer,int vX,int vY,bool pShoot, bool pPause,bool pChangeMunition)
{
    Player * player = getPlayer(pPlayer);
    if(player && !player->isDead()){
        player->getRocket()->setXVelocity(vX*Rocket::ROCKET_VELOCITY);
        player->getRocket()->setYVelocity(vY*Rocket::ROCKET_VELOCITY);
        if (pShoot)player->shoot();
        if (pPause)this->pauseGame();
        if(pChangeMunition)player->changeMunition();
    }
}

bool KernelGame::isRunning()
{
    return _isRunning;
}



void KernelGame::createPlayer()
{
    _NumOfPlayer++;
    _Players.add(new Player(0,0,_NumOfPlayer));
}

//==================================================================================================
// 05 FINAL DE MANEJO DE JUGADORES
//==================================================================================================















//==================================================================================================
// 06 PAUSA Y PLAY
//==================================================================================================

void KernelGame::pauseGame()
{
    _Paused = !_Paused;
}

void KernelGame::play(Player *pPlayer){
    if (pPlayer->getPlayerNumber() == 1 || pPlayer->getPlayerNumber() == _PlayerPause)_Paused = false;
}

void KernelGame::stop()
{
    _isRunning = false;
}

bool KernelGame::isPaused()
{
    return _Paused;
}

//==================================================================================================
// 06 FINAL DE PAUSA Y PLAY
//==================================================================================================


















//==================================================================================================
// 07 DESTRUCTOR
//==================================================================================================
KernelGame::~KernelGame()
{
    for(int x = 0; x < _Enemies.getLenght(); x++)delete _Enemies.get(x);
    for(int x = 0; x < _Players.getLenght(); x++)delete _Players.get(x);
    for(int x = 0; x < _EnemiesShots.getLenght(); x++)delete _EnemiesShots.get(x);

}
//==================================================================================================
// 07 FINAL DESTRUCTOR
//==================================================================================================
