#include "qpixmap.h"
#include "hpentity.h"
#include "shot.h"
#ifndef ROCKET_H
#define ROCKET_H

class Rocket : public HPEntity
{
protected:
    //Velocidad en el eje X
    int _Vx;
    //Velocidad en el eje Y
    int _Vy;
public:
    //Constructor solicita la vida que tendra la nave
    Rocket(QRect pRectangle, int pMaxHp);
    //Actualiza la posicion de la nave
    void update();
    //Setea la velocidad en el eje x
    void setXVelocity(int pXVelocity);
    //Setea la velocidad en el eje y
    void setYVelocity(int pYVelocity);

    //obtiene la velocidad en el eje x
    int getXVelocity() const;

    //obtiene la velocidad en el eje y
    int getYVelocity() const;

    // crea un disparo en la posicion frontal de la nave
    virtual Shot* shoot() = 0;
    //Liberador de memeoria
    virtual ~Rocket();
};

#endif // ROCKET_H
