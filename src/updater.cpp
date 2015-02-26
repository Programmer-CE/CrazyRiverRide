#include "updater.h"
#include <QMutex>
Updater::Updater(QObject *parent) :
    QThread(parent),open(true)
{
}

void Updater::setRunTarget(GameManager *ogm)
{
    gm = ogm;
}

void Updater::run()
{
    while(open){
        QMutex m;
        m.lock();
        gm->runAGame();
        emit renderGame();
        m.unlock();
        this->msleep(42);

    }
}

void Updater::setActive(bool b)
{
    open = b;
}
