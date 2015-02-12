#include "crazyriverride.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CrazyRiverRide w;
    w.show();

    return a.exec();
}
