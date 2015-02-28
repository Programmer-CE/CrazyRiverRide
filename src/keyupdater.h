#include "logic/patterdesing/observer.h"
#include "logic/kernelgame.h"
#ifndef KEYUPDATER_H
#define KEYUPDATER_H

class KeyUpdater:public Observer
{
    KernelGame *_KernelGame;
public:
    KeyUpdater(KernelGame *kg);
    KeyUpdater();
    void update(google::protobuf::Message *pMessage);
};

#endif // KEYUPDATER_H
