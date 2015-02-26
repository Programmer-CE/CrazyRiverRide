#include "crazyriverride.h"
#include "gamemanager.h"
#include <QApplication>
#include "QThread"
#include "updater.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrazyRiverRide w;
    w.show();
    Updater *mthread = new Updater(&w);
    w.connect(mthread,SIGNAL(renderGame()),&w,SLOT(render()));
    GameManager gm(&w);
    mthread->setRunTarget(&gm);
    mthread->start();
    /*
    while(w.isVisible()){
        gm.runAGame();
    }
    */
    return a.exec();
}
