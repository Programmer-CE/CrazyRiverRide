#include "keyupdater.h"
#include "protobufmessage/ControlPlayer.pb.h"
KeyUpdater::KeyUpdater(KernelGame *pKernelGame)
{
    _KernelGame = pKernelGame;
}

KeyUpdater::KeyUpdater()
{

}

void KeyUpdater::update(google::protobuf::Message *pMessage)
{
    if(ControlPlayer().GetTypeName() == pMessage->GetTypeName()){
        ControlPlayer *cp = (ControlPlayer*)pMessage;
        _KernelGame->updatePlayerPosition(cp->num_of_player(),cp->xvelocity(),cp->yvelocity());
    }
}
