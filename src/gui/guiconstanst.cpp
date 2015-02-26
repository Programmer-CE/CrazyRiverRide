#include <gui/guiconstanst.h>

GuiConstanst::GuiConstanst()
{
    _player1 = QPixmap(":/images/images/player/mini blue rocket.png");
    _player2 = QPixmap(":/images/images/player/mini gray rocket.png");
    _player3 = QPixmap(":/images/images/player/mini green rocket.png");
    _player4 = QPixmap(":/images/images/player/mini metroid rocket.png");
    _player5 = QPixmap(":/images/images/player/mini premium rocket.png");
    _player6 = QPixmap(":/images/images/player/mini purple rocket.png");
    _player7 = QPixmap(":/images/images/player/mini red rocket.png");

    _playerArray[0]=_player1;
    _playerArray[1]=_player2;
    _playerArray[2]=_player3;
    _playerArray[3]=_player4;
    _playerArray[4]=_player5;
    _playerArray[5]=_player6;
    _playerArray[6]=_player7;

    _bossArray[0]= _boss1;
    _bossArray[1]= _boss2;
    _bossArray[2]= _boss3;
    _bossArray[3]= _boss4;
    _bossArray[4]= _boss5;
    _bossArray[5]= _boss6;

    _bGArray[0]= _bG1;
    _bGArray[1]= _bG2;
    _bGArray[2]= _bG3;
    _bGArray[3]= _bG4;
    _bGArray[4]= _bG5;


    // falta las imagenes que van a ser utilizadas como enemigos y jefes
}
QPixmap* GuiConstanst::getBridge()
{
    return &_bridge;
}
QPixmap* GuiConstanst::getKamikazeEnemy()
{
    return &_kamikaseEnemy;
}
QPixmap* GuiConstanst::getMovilEnemy()
{
    return &_movilEnemy;
}
QPixmap* GuiConstanst::getPlayer(int pNumOfPlayer)
{
    return &(_playerArray[pNumOfPlayer]);
}
QPixmap* GuiConstanst::getBoss(int pNumOfBoss)
{
    return &(_bossArray[pNumOfBoss]);
}
QPixmap* GuiConstanst::getBackGround(int pNumOfBackGround)
{
    return &(_bGArray[pNumOfBackGround]);
}
GuiConstanst::~GuiConstanst()
{

}
