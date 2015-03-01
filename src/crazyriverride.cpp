#include "crazyriverride.h"
#include "ui_crazyriverride.h"
#include "qpaintengine.h"
#include "protobufmessage/ControlPlayer.pb.h"
#include "protobufmessage/Stop.pb.h"
#include "QVariant"


CrazyRiverRide::CrazyRiverRide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrazyRiverRide), _PausedCalled(false),_Paused(false),_Close(false),_Shoot(false),_ChangeMunition(false),
    playerlife(0),playerpoints(0),playermunition(0),playerCombustible(0)
{
    ui->setupUi(this);
    KeyXaxis = 0;
    KeyYaxis = 0;
    nextKeyXaxis = 0;
    nextKeyYaxis = 0;
    indicadorPlayer = QFont();
    indicadorPlayer.setPixelSize(14);
    indicadorPlayer.setBold(true);
    music.setMedia(QUrl("qrc:/music/sound/metalstarforce.mp3"));
    music.play();
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
    if (!_Paused){
        while(!queue.isEmpty()){
            PaintTask pt= queue.dequeue();
            p.drawPixmap(pt.getRec().topLeft(),*pt.getPix());
        }
        p.setBrush(QBrush(QColor(Qt::black)));
        p.setFont(indicadorPlayer);
        QString info("HP: ");
        QVariant variant(playerlife);
        p.drawText(20,20,info.append(variant.toString()));
        info = "Points: ";
        variant = QVariant(playerpoints);
        p.drawText(20,35,info.append(variant.toString()));
        info = "Munitions: ";
        variant = QVariant(playermunition);
        p.drawText(20,50,info.append(variant.toString()));
        info = "Combustible: ";
        variant = QVariant(playerCombustible);
        p.drawText(20,65,info.append(variant.toString()));
    }
    else{
        indicadorPlayer.setPixelSize(150);
        QBrush b;
        b.setColor(Qt::black);
        p.setBrush(b);
        p.setFont(indicadorPlayer);
        p.fillRect(rect(),Qt::black);
        p.drawText(200,500,"PAUSED");
        indicadorPlayer.setPixelSize(14);
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
        case Qt::Key_P:
            _PausedCalled = !_PausedCalled;
            _Paused = !_Paused;
            if (_Paused){
                music.pause();
            }
            else{
                music.play();
            }
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
int CrazyRiverRide::getPlayerCombustible() const
{
    return playerCombustible;
}

void CrazyRiverRide::setPlayerCombustible(int value)
{
    playerCombustible = value;
}

void CrazyRiverRide::playmusic()
{
    music.play();
}

int CrazyRiverRide::getPlayermunition() const
{
    return playermunition;
}

void CrazyRiverRide::setPlayermunition(int value)
{
    playermunition = value;
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
    mensaje->set_pause(_PausedCalled);
    if (_PausedCalled) _PausedCalled = false;
    mensaje->set_shoot(_Shoot);
    mensaje->set_changemunition(_ChangeMunition);
    _KeyUpdater.update(mensaje);
    delete mensaje;
}
