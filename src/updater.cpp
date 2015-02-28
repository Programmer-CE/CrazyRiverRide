#include "updater.h"
#include <QMutex>
Updater::Updater(QObject *parent) :
    QThread(parent),open(true)
{
}

void Updater::setRunTarget(KernelGame *ogm)
{
    gm = ogm;
}

void Updater::run()
{
    while(gm->isRunning()){
        QMutex m;
        m.lock();
        gm->update(gm->getRect());
        emit renderGame();
        m.unlock();
        this->msleep(42);

    }
}

void Updater::setActive(bool b)
{
    open = b;
}
