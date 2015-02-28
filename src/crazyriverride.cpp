#include "crazyriverride.h"
#include "ui_crazyriverride.h"
#include "qpaintengine.h"
#include "protobufmessage/ControlPlayer.pb.h"

CrazyRiverRide::CrazyRiverRide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrazyRiverRide)
{
    ui->setupUi(this);
    KeyXaxis = 0;
    KeyYaxis = 0;
    nextKeyXaxis = 0;
    nextKeyYaxis = 0;
    setGeometry(0,0,800,800);
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

void CrazyRiverRide::setkeyUpdater(KeyUpdater pKeyUpdater)
{
    _KeyUpdater = pKeyUpdater;
}

CrazyRiverRide::~CrazyRiverRide()
{
    delete ui;
}

void CrazyRiverRide::closeEvent(QCloseEvent *)
{

}

void CrazyRiverRide::paintEvent(QPaintEvent *)
{
    p.begin(this);
    while(!queue.isEmpty()){
        PaintTask pt= queue.dequeue();
        p.drawPixmap(pt.getRec().topLeft(),*pt.getPix());
    }
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
    }
}

void CrazyRiverRide::render()
{
    repaint();
    ControlPlayer *mensaje = new ControlPlayer();
    mensaje->set_num_of_player(0);
    mensaje->set_xvelocity(getKeyXaxis());
    mensaje->set_yvelocity(getKeyYaxis());
    _KeyUpdater.update(mensaje);
    delete mensaje;
}
