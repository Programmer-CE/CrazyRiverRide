#include "crazyriverride.h"
#include "logic/kernelgame.h"
#include "qpixmap.h"
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager
{
    KernelGame *_KernelGame;
    CrazyRiverRide *_GameWindows;
    QRect r;
    QPixmap pix;
public:
    GameManager(CrazyRiverRide *);
    void runAGame();
    ~GameManager();
};

#endif // GAMEMANAGER_H
