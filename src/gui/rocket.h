#include "qpixmap.h"
#include "hpentity.h"
#include "shoot.h"
#ifndef ROCKET_H
#define ROCKET_H

class Rocket : public HPEntity
{
protected:
    //Velocidad en el eje X
    int _Vx;
    //Velocidad en el eje Y
    int _Vy;
    //Puntero a la imagen que la nave pinta
    QPixmap *_Sprite;
public:
    //Constructor solicita la vida que tendra la nave
    Rocket(int pMaxHp);
    //Actualiza la posicion de la nave
    void update();
    //Setea la velocidad en el eje x
    void setXVelocity(int pXVelocity);
    //Setea la velocidad en el eje y
    void setYVelocity(int pYVelocity);
    //render: renderiza la nave en un lugar dado
    void render(QPainter *pPainter);
    // crea un disparo en la posicion frontal de la nave
    virtual Shoot* shoot() = 0;
};

#endif // ROCKET_H
