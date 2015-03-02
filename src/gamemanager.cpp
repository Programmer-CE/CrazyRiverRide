#include "gamemanager.h"
#include "iostream"
#include <protobufmessage/GameObjectNotify.pb.h>
#include <protobufmessage/PlayerStatus.pb.h>
#include <string>
#include "logic/shot/shot.h"
#include "protobufmessage/GameMenu.pb.h"
#include "protobufmessage/SelectMap.pb.h"
#include "protobufmessage/ChangePhase.pb.h"


GameManager::GameManager(CrazyRiverRide *gw):
    player1(":/images/images/player/mini blue rocket.png"),
    enemies(":/images/images/enemy/mini enemy nave premium version.png"),
    level(":/images/images/levels/bg.jpg"),
    enemyshot(":/images/images/attack/greenattack.png"),
    playershot(":/images/images/attack/attack.png"),
    indicadorSimpleshot(":/images/images/indicador/simpleshot.png"),
    indicadorDifusionShot(":/images/images/indicador/difusionshot.png"),
    indicadorMayhemShot(":/images/images/indicador/mayhemsimpleshot.png"),
    boxAmount(":/images/images/boxes/amount.png"),
    boxHp(":/images/images/boxes/healt.png"),
    boxBadHp(":/images/images/boxes/unhealt.png"),
    boxCombustible(":/images/images/boxes/cumbustible.png"),
    boxBadCombustible(":/images/images/boxes/flame.png"),
    level2(":/images/images/levels/bg_2.jpg"),
    level3(":/images/images/levels/bg_3.jpg"),
    level4(":/images/images/levels/bg_4.jpg"),
    level5(":/images/images/levels/bg_5.jpg"),
    _Run(true)
{
    r = gw->rect();
    r.setX(0);
    r.setY(0);
    currentMap = 0;
    _GameWindows = gw;
}

void GameManager::runAGame()
{
    //_GameWindows->paintImage(_KernelGame->getPlayerRect(0),&pix);
}

void GameManager::select(int Map)
{
    switch (Map) {
    case 1:
        currentMap = &level;
        break;
    case 2:
        currentMap = &level2;
        break;
    case 3:
        currentMap = &level3;
        break;
    case 4:
        currentMap = &level4;
        break;
    case 5:
        currentMap = &level5;
        break;
    }
    currentMap = &level;
}

void GameManager::update(google::protobuf::Message *pMessage)
{
    if (_GameWindows && _GameWindows->isRunning()){
        if (pMessage->GetTypeName() == GameObjectNotify().GetTypeName()){
            GameObjectNotify *gon = (GameObjectNotify*)pMessage;
            if (gon->type() == 0){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),currentMap);
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
            else if (gon->type() == 5){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&boxAmount);
            }
            else if (gon->type() == 6){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&boxCombustible);
            }
            else if (gon->type() == 7){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&boxBadCombustible);
            }
            else if (gon->type() == 8){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&boxHp);
            }
            else if (gon->type() == 9){
                _GameWindows->paintImage(QRect(gon->x(),gon->y(),gon->width(),gon->height()),&boxBadHp);
            }

        }
        else if (pMessage->GetTypeName() == PlayerStatus().GetTypeName()){
            PlayerStatus *playerstatus = (PlayerStatus*)pMessage;
            _GameWindows->setPlayerlife(playerstatus->playerlife());
            _GameWindows->setPlayerpoints(playerstatus->playerpoints());
            _GameWindows->setPlayermunition(playerstatus->numofmunition());
            _GameWindows->setPlayerCombustible(playerstatus->combustible());
            if (playerstatus->typeofmunition() == Shot::LINEAR_SHOT){
                _GameWindows->paintImage(QRect(950,20,50,50),&indicadorSimpleshot);
            }
            else if ((playerstatus->typeofmunition() == Shot::ANGLE_SHOT)){
                _GameWindows->paintImage(QRect(950,20,50,50),&indicadorDifusionShot);
            }
            else if ((playerstatus->typeofmunition() == Shot::MAYHEM_SHOT)){
                _GameWindows->paintImage(QRect(950,20,50,50),&indicadorMayhemShot);
            }

        }
        else if (pMessage->GetTypeName() == GameMenu().GetTypeName()){
            GameMenu *menuoption = (GameMenu*)pMessage;
            QRect(menuoption->buttonx(),menuoption->buttony(),menuoption->buttonwidth(),menuoption->buttonheight());
        }
        else if(pMessage->GetTypeName() == SelectMap().GetTypeName()){
            SelectMap *menuoption = (SelectMap*)pMessage;
            select(menuoption->numofmap());
            _GameWindows->setRenderinType(true,false);
            _GameWindows->setRenderinType(false,false);
        }
        else if(pMessage->GetTypeName() == ChangePhase().GetTypeName()){
            ChangePhase *phase = (ChangePhase*)pMessage;
            switch (phase->numofphase()) {
            case 1:
                //caso 1 menu
                _GameWindows->setRenderinType(true,false);
                break;
            case 2:
                //caso 2 juego
                _GameWindows->setRenderinType(false,false);
                break;
            case 3:
                //caso 3 juego con jefe
                _GameWindows->setRenderinType(false,false);
                break;
            case 4:
                //caso siguiente nivel
                _GameWindows->setRenderinType(false,false);
                break;
            case 5:
                //caso 5 game over
                _GameWindows->setRenderinType(false,true);
                break;
            default:
                break;
            }
        }
    }
}


GameManager::~GameManager()
{
}
