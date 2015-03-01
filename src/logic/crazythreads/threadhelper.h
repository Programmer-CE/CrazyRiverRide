#ifndef THREADHELPER_H
#define THREADHELPER_H

#include <QObject>

class ThreadHelper : public QObject
{
    Q_OBJECT
public:
    explicit ThreadHelper(QObject *parent = 0);

signals:
    void renderGame();
public slots:

};

#endif // THREADHELPER_H
