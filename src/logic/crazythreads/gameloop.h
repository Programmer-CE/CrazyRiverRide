#include "crazythread.h"
#include "logic/kernelgame.h"
#include "logic/crazythreads/threadhelper.h"
#ifndef GAMELOOP_H
#define GAMELOOP_H

class GameLoop:public CrazyThread
{
    KernelGame * _KernelGame;
    ThreadHelper * guiConector;
protected:
    void internalRun();
public:
    GameLoop(KernelGame *pKernelGame);
    virtual ~GameLoop();
    ThreadHelper* getGuiConector() const;
};

#endif // GAMELOOP_H
