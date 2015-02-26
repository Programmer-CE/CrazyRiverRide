#include "gamemanager.h"
#include "iostream"

GameManager::GameManager(CrazyRiverRide *gw):pix(":/images/images/player/mini blue rocket.png")
{
    r = gw->rect();
    r.setX(0);
    r.setY(0);
    _KernelGame = new KernelGame(r);
    _GameWindows = gw;
}

void GameManager::runAGame()
{

    Player* p1 = _KernelGame->getPlayer(0);
    if (p1){
        std::cout << "x: " << p1->getRocket()->getX() << " y: "<< p1->getRocket()->getY()  << std::endl;
        std::cout << "w: " << p1->getRocket()->getWidth() << " h: "<< p1->getRocket()->getHeight()  << std::endl;
        p1->getRocket()->setXVelocity(_GameWindows->getKeyXaxis()*10);
        p1->getRocket()->setYVelocity(_GameWindows->getKeyYaxis()*10);
        _KernelGame->update(r);
        _GameWindows->paintImage(p1->getRocket()->getRect(),&pix);
    }
    else{
        std::cout << "oh no here!" << std::endl;
    }
}

GameManager::~GameManager()
{
    delete _KernelGame;
    _KernelGame = 0;
}
