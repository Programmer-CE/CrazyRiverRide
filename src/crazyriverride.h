#include "qpainter.h"
#include "painttask.h"
#include "QKeyEvent"
#include "controlStructure/Queue.h"
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
    ~CrazyRiverRide();
protected:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
private:
    Ui::CrazyRiverRide *ui;
    int KeyXaxis,KeyYaxis,nextKeyXaxis,nextKeyYaxis;
    QPainter p;
    Queue<PaintTask> queue;
public slots:
    void render();
};

#endif // CRAZYRIVERRIDE_H
