#include "gamemanager.h"
#include "iostream"
#include <protobufmessage/GameObjectNotify.pb.h>
#include <string>

GameManager::GameManager(CrazyRiverRide *gw):pix(":/images/images/player/mini blue rocket.png"),_Run(true)
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
    if (pMessage->GetTypeName() == GameObjectNotify().GetTypeName()){
        GameObjectNotify *gon = (GameObjectNotify*)pMessage;
        _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&pix);
    }
}


GameManager::~GameManager()
{
}
