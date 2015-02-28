#include "gamemanager.h"
#include "iostream"
#include <protobufmessage/GameObjectNotify.pb.h>
#include <protobufmessage/PlayerStatus.pb.h>
#include <string>
#include "logic/shot/shot.h"

GameManager::GameManager(CrazyRiverRide *gw):
    player1(":/images/images/player/mini blue rocket.png"),
    enemies(":/images/images/enemy/mini enemy nave premium version.png"),
    level(":/images/images/levels/bg.jpg"),
    enemyshot(":/images/images/attack/greenattack.png"),
    playershot(":/images/images/attack/attack.png"),
    indicadorSimpleshot(":/images/images/indicador/simpleshot.png"),
    indicadorDifusionShot(":/images/images/indicador/difusionshot.png"),
    indicadorMayhemShot(":/images/images/indicador/mayhemsimpleshot.png")
  ,_Run(true)
{
    r = gw->rect();
    r.setX(0);
    r.setY(0);
    _GameWindows = gw;
}

void GameManager::runAGame()
{
    //_GameWindows->paintImage(_KernelGame->getPlayerRect(0),&pix);
}

void GameManager::update(google::protobuf::Message *pMessage)
{
    if (_GameWindows && _GameWindows->isRunning()){
        if (pMessage->GetTypeName() == GameObjectNotify().GetTypeName()){
            GameObjectNotify *gon = (GameObjectNotify*)pMessage;
            if (gon->type() == 0){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&level);
            }
            else if (gon->type() == 1){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&player1);
            }
            else if (gon->type() == 2){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&enemies);
            }
            else if (gon->type() == 3){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&enemyshot);
            }
            else if (gon->type() == 4){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&playershot);
            }
        }
        else if (pMessage->GetTypeName() == PlayerStatus().GetTypeName()){
            PlayerStatus *playerstatus = (PlayerStatus*)pMessage;
            _GameWindows->setPlayerlife(playerstatus->playerlife());
            _GameWindows->setPlayerpoints(playerstatus->playerpoints());
            _GameWindows->setPlayermunition(playerstatus->numofmunition());
            if (playerstatus->typeofmunition() == Shot::LINEAR_SHOT){
                _GameWindows->paintImage(QRect(950,0,50,50),&indicadorSimpleshot);
            }
            else if ((playerstatus->typeofmunition() == Shot::ANGLE_SHOT)){
                _GameWindows->paintImage(QRect(950,0,50,50),&indicadorDifusionShot);
            }
            else if ((playerstatus->typeofmunition() == Shot::MAYHEM_SHOT)){
                _GameWindows->paintImage(QRect(950,0,50,50),&indicadorMayhemShot);
            }

        }
    }
}


GameManager::~GameManager()
{
}
