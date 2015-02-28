#include "crazyriverride.h"
#include "gamemanager.h"
#include "logic/kernelgame.h"
#include <QApplication>
#include "QThread"
#include "updater.h"
#include "keyupdater.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrazyRiverRide w;
    KernelGame *kernel = new KernelGame(w.rect());
    KeyUpdater keyupdater(kernel);
    w.setkeyUpdater(keyupdater);
    w.show();
    Updater mthread(&w);
    w.connect(&mthread,SIGNAL(renderGame()),&w,SLOT(render()));
    GameManager gm(&w);
    kernel->setObserver(&gm);
    mthread.setRunTarget(kernel);
    mthread.start();
    /*
    while(w.isVisible()){
        gm.runAGame();
    }
    */
    if (mthread.isRunning())
    return a.exec();
}
