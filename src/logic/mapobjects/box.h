#include "logic/mapobjects/hpentity.h"
#include "logic/player.h"

#ifndef BOX_H
#define BOX_H

/**
 * @brief Es la clase caja que se encarga de agregar puntos de vida al jugador, tambien se encarga de quitarle
 * puntos si se ha convertido en una caja envenenada
 *
 */
class Box: public HPEntity
{
protected:
    int _PointsToAdd; /**< TODO son los puntos que agregara*/
public:
    /**
     * @brief Es el constructor de la clase box le da una posicion (x,y) y dimensiones, una cantidad de vida
     * maxima y la cantidad de puntos que agregara
     *
     * @param pRect Es el rectangulo que contiene la posicion y las dimensiones de la caja
     * @param pMaxHp es la cantidad de vida maxima que esta contiene
     * @param pPointsToAdd es la cantidad de vida que se agregara o sustreara del jugador
     */
    Box(QRect pRect, int pMaxHp,int pPointsToAdd);
    /**
     * @brief Es el metodo que se encarga de sumar o restar directamente la vida al jugador
     *
     * @param pPlayer es el jugador al que se le aplica la operacion de suma o resta de vida
     */
    virtual void addPointsToPlayer(Player *pPlayer);
    /**
     * @brief Este metodo se encarga de tornar la caja en una caja mala volviedo los puntos que esta contiene
     * en puntos negativos que afectaran directamente sobre el jugador
     *
     */
    void turnAbadBox();
    /**
     * @brief Verifica si la caja es mala, osea perjudica al jugador
     *
     * @return true, si la caja es mala
     */
    bool isBadBox();
    /**
     * @brief Actualiza las posiciones y puntos de la caja
     *
     */
    void update();
    /**
     * @brief Destructor virtual de la clase
     *
     */
    virtual ~Box();
};

#endif // BOX_H
