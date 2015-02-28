#include "logic/mapobjects/gameobject.h"
#include "logic/mapobjects/hpentity.h"
#ifndef SHOT_H
#define SHOT_H
class Shot: public GameObject
{
protected:
    int _Damage;
public:
    //Velocidad comun del disparo
    static const int VELOCITY;
    //Numero que representa el tipo de disparo de angulo
    static const int ANGLE_SHOT;
    //Numero que representa el tipo de disparo linear
    static const int LINEAR_SHOT;
    //Numero que representa el tipo de disparo mayhem
    static const int MAYHEM_SHOT;
    //Numero que representa el ancho del disparo
    static const int WIDTH_SHOT;
    //Numero que representa el alto del disparo
    static const int HEIGHT_SHOT;
    //Numero que representa la cantidad de salud que resta un disparo enemigo
    static const int ENEMY_DAMAGE;
    //Numero que representa la cantidad de salud que resta un disparo mayhem
    static const int MAYHEM_DAMAGE;
    //Numero que representa la cantidad de salud que resta un disparo angular
    static const int ANGULAR_DAMAGE;
    //Numero que representa la cantidad de salud que resta un disparo linear
    static const int LINEAR_DAMAGE;
    //Bandera que representa si el disparo se dirige hacia arriba
    static const bool SHOT_TO_UP;
    //Bandera que representa si el disparo se dirige hacia abajo
    static const bool SHOT_TO_DOWN;

    Shot(QRect pRectangle, int pDamage);
    void damage(HPEntity *pEntity);
    virtual bool isUsefulShot(QRect pArea)=0;
    virtual int getXVelocity()=0;
    virtual int getYVelocity()=0;
    virtual int getType()=0;
    virtual ~Shot(){}
};
#endif // SHOT_H
