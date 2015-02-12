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
    ~CrazyRiverRide();

private:
    Ui::CrazyRiverRide *ui;
};

#endif // CRAZYRIVERRIDE_H
