#include "keyupdater.h"
#include "protobufmessage/ControlPlayer.pb.h"
#include "protobufmessage/Stop.pb.h"
#include "QMutex"
#include "QMutexLocker"
KeyUpdater::KeyUpdater(KernelGame *pKernelGame)
{
    _KernelGame = pKernelGame;
}

KeyUpdater::KeyUpdater()
{

}

void KeyUpdater::update(google::protobuf::Message *pMessage)
{
    //QMutex m;
    //m.lock();
    if(ControlPlayer().GetTypeName() == pMessage->GetTypeName()){
        ControlPlayer *cp = (ControlPlayer*)pMessage;
        _KernelGame->updatePlayerPosition(cp->num_of_player(),cp->xvelocity(),cp->yvelocity(),cp->shoot(),cp->pause(),cp->changemunition());
    }
    else if(Close().GetTypeName() == pMessage->GetTypeName()){
        _KernelGame->stop();
    }
    //m.unlock();

}
