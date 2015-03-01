#include "crazyriverride.h"
#include "gamemanager.h"
#include "logic/kernelgame.h"
#include <QApplication>
#include "QThread"
#include "updater.h"
#include "keyupdater.h"
#include "logic/crazythreads/gameloop.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrazyRiverRide w;
    KernelGame *kernel = new KernelGame(w.rect());
    KeyUpdater keyupdater(kernel);
    w.setkeyUpdater(keyupdater);
    w.show();
    GameLoop mthread(kernel);
    //Updater mthread(&w);
    //w.connect(mthread.getGuiConector(),SIGNAL(renderGame()),&w,SLOT(render()));
    GameManager gm(&w);
    kernel->setObserver(&gm);
    mthread.start();
    /*
    while(w.isVisible()){
        gm.runAGame();
    }
    */
    //if (mthread.isRunning())
    return a.exec();
}
