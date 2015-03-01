#include "gameloop.h"
#include "unistd.h"
ThreadHelper* GameLoop::getGuiConector() const
{
    return guiConector;
}

void GameLoop::internalRun()
{
    while(_KernelGame->isRunning()){
        if (_KernelGame){
            emit guiConector->renderGame();
            _KernelGame->update(_KernelGame->getRect());
        }
        usleep(KernelGame::FPS*1000);
    }
    delete _KernelGame;
}

GameLoop::GameLoop(KernelGame *pKernelGame)
{
    _KernelGame = pKernelGame;
    guiConector = new ThreadHelper;
}

GameLoop::~GameLoop()
{
    while(_KernelGame->isRunning())_KernelGame->stop();
    delete guiConector;
}
