#include "qpainter.h"
#include "painttask.h"
#include "QKeyEvent"
#include "controlStructure/Queue.h"
#include "keyupdater.h"
#include "qmediaplayer.h"
#ifndef CRAZYRIVERRIDE_H
#define CRAZYRIVERRIDE_H

#include <QMainWindow>

namespace Ui {
class CrazyRiverRide;
}

class CrazyRiverRide : public QMainWindow
{
    Q_OBJECT

public:
    explicit CrazyRiverRide(QWidget *parent = 0);
    void paintImage(QRect rec, QPixmap *pImage);
    int getKeyXaxis();
    int getKeyYaxis();
    bool isRunning();
    void setkeyUpdater(KeyUpdater pKeyUpdater);
    ~CrazyRiverRide();
    int getPlayerlife() const;
    void setPlayerlife(int value);

    int getPlayerpoints() const;
    void setPlayerpoints(int value);

    int getPlayermunition() const;
    void setPlayermunition(int value);
    void setRenderinType(bool isOnMenu,bool isGameOver);
    int getPlayerCombustible() const;
    void setPlayerCombustible(int value);
    void addRectangle(QRect dimension, bool isSelected, int text);
    void playmusic();
protected:
    void closeEvent(QCloseEvent *);
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
private:
    Ui::CrazyRiverRide *ui;
    bool _PausedCalled,_Paused, _Close, _Shoot, _ChangeMunition;
    int KeyXaxis,KeyYaxis,nextKeyXaxis,nextKeyYaxis;
    int playerlife,playerpoints,playermunition,playerCombustible;
    bool _Menu,_GameOver;
    QPainter p;
    Queue<PaintTask> queue;
    KeyUpdater _KeyUpdater;
    QFont indicadorPlayer;
    QMediaPlayer music;
public slots:
    void render();
};

#endif // CRAZYRIVERRIDE_H
