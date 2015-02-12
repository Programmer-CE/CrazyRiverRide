#include "crazyriverride.h"
#include "ui_crazyriverride.h"

CrazyRiverRide::CrazyRiverRide(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CrazyRiverRide)
{
    ui->setupUi(this);
}

CrazyRiverRide::~CrazyRiverRide()
{
    delete ui;
}
