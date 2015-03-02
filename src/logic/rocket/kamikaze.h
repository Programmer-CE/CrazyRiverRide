#include "enemyrocket.h"
#include "logic/player.h"
#ifndef KAMIKAZE_H
#define KAMIKAZE_H

/**
 * @brief La clase kamikaze representa a una nave detectora sige al jugador y detecta su posicion
 *
 */
class Kamikaze:public EnemyRocket
{
    Player *_PlayerToFollow; /**< TODO puntero al jugador a seguir*/
public:
    /**
     * @brief Es el metodo constructor al igual que su clase padre contiene el rectangulo que
     * ubica la nave y tiene sus dimensiones, un entero que representa la vida maxima de este tipo de nave y
     * finalmente incorpora un parametro nuevo un puntero al jugador que va a seguir
     *
     * @param pRectangle representa el tamaño y ubicacion del objeto a instanciar con el constructor
     * @param pMaxHp la vida maxima de la nave kamikaze
     * @param pPlayerToFollow es el puntero al jugador a seguir
     */
    Kamikaze(QRect pRectangle, int pMaxHp,Player * pPlayerToFollow);
    /**
     * @brief Es un metodo sobrescrito y retorna la constante que representa a las naves kamizake
     *
     * @return @link{EnemyRocket::KAMIKAZE}
     */
    int getEnemyType();
    /**
     * @brief Se sobrescribe el metodo de la clase superior y por medio de este es que se calcula la
     * posicion de la nave kamikaze para poder seguir al jugador.
     *
     */
    void update();

    virtual ~Kamikaze(){}
};

#endif // KAMIKAZE_H
