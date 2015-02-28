#include "gamemanager.h"
#include "iostream"
#include <protobufmessage/GameObjectNotify.pb.h>
#include <protobufmessage/PlayerStatus.pb.h>
#include <string>

GameManager::GameManager(CrazyRiverRide *gw):
    player1(":/images/images/player/mini blue rocket.png"),
    enemies(":/images/images/enemy/mini enemy nave premium version.png"),
    level(":/images/images/levels/bg.jpg"),
    enemyshot(":/images/images/attack/greenattack.png"),
    playershot(":/images/images/attack/attack.png")
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
            std::cout << "is player status" << std::endl;
            PlayerStatus *playerstatus = (PlayerStatus*)pMessage;
            _GameWindows->setPlayerlife(playerstatus->playerlife());
            _GameWindows->setPlayerpoints(playerstatus->playerpoints());

        }
    }
}


GameManager::~GameManager()
{
}
