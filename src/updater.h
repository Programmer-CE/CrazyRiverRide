#ifndef UPDATER_H
#define UPDATER_H

#include <QThread>
#include "gamemanager.h"

class Updater : public QThread
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);
    void setRunTarget(GameManager *ogm);
    void run();
    void setActive(bool b);
    bool isClose();

private:
    bool open;
    GameManager *gm;
signals:
    void renderGame();
public slots:

};

#endif // UPDATER_H
