#include "logic/mapobjects/box.h"
#ifndef COMBUSTIBLEBOX_H
#define COMBUSTIBLEBOX_H

/**
 * @brief Es la caja que da combustible al jugador, o resta vida si el combustible ha sido consumido por los
 * disparos del jugador(es)
 *
 */
class CombustibleBox:public Box
{
public:
    /**
     * @brief Es el constructor de la clase box le da una posicion (x,y) y dimensiones, una cantidad de vida
     * maxima y la cantidad de puntos de combustible que agregara
     *
     * @param pRect Es el rectangulo que contiene la posicion y las dimensiones de la caja
     * @param pMaxHp es la cantidad de vida maxima que esta contiene
     * @param pPointsToAdd es la cantidad de combustible que se agregara o sustreara del jugador
     */
    CombustibleBox(QRect pRect, int pMaxHp,int pPointsToAdd);
    /**
     * @brief Es el metodo que se encarga de sumar el combustible o restar directamente la vida al jugador
     *
     * @param pPlayer es el jugador al que se le aplica la operacion de suma o resta de vida o combustible
     */
    void addPointsToPlayer(Player *pPlayer);
    /**
     * @brief Actualiza la posicion de la caja de combustible
     *
     */
    void update();
    /**
     * @brief Destructor de la clase
     *
     */
    virtual ~CombustibleBox();

};

#endif // COMBUSTIBLEBOX_H
