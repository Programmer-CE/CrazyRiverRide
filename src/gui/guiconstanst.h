#ifndef GUICONSTANST_H
#define GUICONSTANST_H
#include <QPaintEvent>
#include <qpixmap.h>

class GuiConstanst
{
public:
    int numOfPlayer;
    int numOfLevels;

    GuiConstanst();
    virtual ~GuiConstanst();

    QPixmap* getPlayer(int pNumOfPlayer);
    QPixmap* getMovilEnemy();
    QPixmap* getKamikazeEnemy();
    QPixmap* getBoss(int pNumOfBoss);
    QPixmap* getBridge();
    QPixmap* getBackGround(int pNumOfBackground);

private:
    QPixmap _player1;
    QPixmap _player2;
    QPixmap _player3;
    QPixmap _player4;
    QPixmap _player5;
    QPixmap _player6;
    QPixmap _player7;
    QPixmap _movilEnemy;
    QPixmap _kamikaseEnemy;
    QPixmap _boss1;
    QPixmap _boss2;
    QPixmap _boss3;
    QPixmap _boss4;
    QPixmap _boss5;
    QPixmap _boss6;
    QPixmap _bridge;
    QPixmap _bG1;
    QPixmap _bG2;
    QPixmap _bG3;
    QPixmap _bG4;
    QPixmap _bG5;
    QPixmap _bGArray[5];
    QPixmap _playerArray[7];
    QPixmap _bossArray[6];




};

#endif // GUICONSTANST_H










