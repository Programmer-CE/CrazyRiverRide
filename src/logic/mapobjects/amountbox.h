#include "box.h"
#ifndef AMOUNTBOX_H
#define AMOUNTBOX_H

/**
 * @brief Esta clase es la que se encarga de dar municiones al personaje, es la caja que aparece aleatoriamente
 * sobre la ventana y da las municiones o disparos
 *
 */
class AmountBox:public Box
{
public:
    /**
     * @brief Constructor de la clase, le da una posicion, una vida maxima que pueda soportar y la cantidad
     * de disparos que le agrega al jugador que colisione con esta
     *
     * @param pRect el rectangulo que contiene las dimensiones y la posicion del mismo
     * @param pMaxHp es la vida maxima del la caja
     * @param pPointsToAdd la cantidad de puntos agregara al jugador con el que colisione
     */
    AmountBox(QRect pRect, int pMaxHp,int pPointsToAdd);
    /**
     * @brief es el metodo que se encarga de agregar o quitar los puntos actuales de la caja
     * sumara o dejara intacto la vida de este, dependiendo de los puntos que esta tenga
     *
     * @param pPlayer es el jugador al cual se le sumaran o sustraera las municiones
     */
    void addPointsToPlayer(Player *pPlayer);
    /**
     * @brief constructor virtual de la clase
     *
     */
    virtual ~AmountBox();
};

#endif // AMOUNTBOX_H
