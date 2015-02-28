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
        if (gm)gm->update(gm->getRect());
        if (parent())emit renderGame();
        m.unlock();
        this->msleep(42);

    }
    delete gm;
}

void Updater::setActive(bool b)
{
    open = b;
}

Updater::~Updater()
{
    while(isRunning())gm->stop();
}
