#include "crazyriverride.h"
#include "ui_crazyriverride.h"
#include "qpaintengine.h"
#include "protobufmessage/ControlPlayer.pb.h"
#include "protobufmessage/Stop.pb.h"
#include "QVariant"

CrazyRiverRide::CrazyRiverRide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrazyRiverRide), _Pause(false),_Close(false),_Shoot(false),_ChangeMunition(false),
    playerlife(0),playerpoints(0)
{
    ui->setupUi(this);
    KeyXaxis = 0;
    KeyYaxis = 0;
    nextKeyXaxis = 0;
    nextKeyYaxis = 0;
    setGeometry(0,0,1024,800);
}

void CrazyRiverRide::paintImage(QRect rec, QPixmap *pImage)
{
    queue.enqueue(PaintTask(rec,pImage));
}

int CrazyRiverRide::getKeyXaxis()
{
    return KeyXaxis;
}

int CrazyRiverRide::getKeyYaxis()
{
    return KeyYaxis;
}

bool CrazyRiverRide::isRunning()
{
    return !_Close;
}

void CrazyRiverRide::setkeyUpdater(KeyUpdater pKeyUpdater)
{
    _KeyUpdater = pKeyUpdater;
}

CrazyRiverRide::~CrazyRiverRide()
{
    _Close = true;
    delete ui;
}

void CrazyRiverRide::closeEvent(QCloseEvent *)
{
    _Close = true;
    Close *mensaje = new Close();
    mensaje->set_close(_Close);
    _KeyUpdater.update(mensaje);
    delete mensaje;
}

void CrazyRiverRide::paintEvent(QPaintEvent *)
{
    p.begin(this);
    while(!queue.isEmpty()){
        PaintTask pt= queue.dequeue();
        p.drawPixmap(pt.getRec().topLeft(),*pt.getPix());
    }
    QString info("HP: ");
    QVariant variant(playerlife);
    p.drawText(0,15,info.append(variant.toString()));
    info = "Points: ";
    variant = QVariant(playerpoints);
    p.drawText(0,30,info.append(variant.toString()));
    p.end();
}

void CrazyRiverRide::keyPressEvent(QKeyEvent *k)
{
    if (!k->isAutoRepeat()){
        switch (k->key()) {
        case Qt::Key_Up:
            if(KeyYaxis == 0){
                KeyYaxis = -1;
                nextKeyXaxis = 0;
            }
            else{
                nextKeyXaxis = -1;
            }
            break;
        case Qt::Key_Left:
            if(KeyXaxis == 0){
                KeyXaxis = -1;
                nextKeyYaxis = 0;
            }
            else{
                nextKeyYaxis = -1;
            }
            break;
        case Qt::Key_Right:
            if(KeyXaxis == 0){
                KeyXaxis = 1;
                nextKeyYaxis = 0;
            }
            else{
                nextKeyYaxis = 1;
            }
            break;
        case Qt::Key_Down:
            if(KeyYaxis == 0){
                KeyYaxis = 1;
                nextKeyXaxis = 0;
            }
            else{
                nextKeyXaxis = 1;
            }
            break;
        case Qt::Key_Enter:
            _Pause = !_Pause;
            break;
        case Qt::Key_Space:
            _Shoot = true;
            break;
        case Qt::Key_Z:
            _ChangeMunition = true;
            break;
        default:
            break;
        }
    }
}

void CrazyRiverRide::keyReleaseEvent(QKeyEvent *k)
{
    if (!k->isAutoRepeat()){
        if (k->key() == Qt::Key_Up || k->key() == Qt::Key_Down){
            KeyYaxis = nextKeyXaxis;
            nextKeyXaxis = 0;
        }
        else if (k->key() == Qt::Key_Right || k->key() == Qt::Key_Left){
            KeyXaxis = nextKeyYaxis;
            nextKeyYaxis = 0;
        }
        else if (k->key() == Qt::Key_Z){
            _ChangeMunition = false;
        }
        else if (k->key() == Qt::Key_Space){
            _Shoot = false;
        }

    }
}
int CrazyRiverRide::getPlayerpoints() const
{
    return playerpoints;
}

void CrazyRiverRide::setPlayerpoints(int value)
{
    playerpoints = value;
}

int CrazyRiverRide::getPlayerlife() const
{
    return playerlife;
}

void CrazyRiverRide::setPlayerlife(int value)
{
    playerlife = value;
}


void CrazyRiverRide::render()
{
    repaint();
    ControlPlayer *mensaje = new ControlPlayer();
    mensaje->set_num_of_player(0);
    mensaje->set_xvelocity(getKeyXaxis());
    mensaje->set_yvelocity(getKeyYaxis());
    mensaje->set_pause(_Pause);
    mensaje->set_shoot(_Shoot);
    _KeyUpdater.update(mensaje);
    delete mensaje;
}
