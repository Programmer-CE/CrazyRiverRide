#ifndef UPDATER_H
#define UPDATER_H

#include <QThread>
#include "logic/kernelgame.h"

class Updater : public QThread
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);
    void setRunTarget(KernelGame *ogm);
    void run();
    void setActive(bool b);
    bool isClose();

private:
    bool open;
    KernelGame *gm;
signals:
    void renderGame();
public slots:

};

#endif // UPDATER_H
