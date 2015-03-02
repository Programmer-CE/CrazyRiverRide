#include "qpixmap.h"
#include "logic/mapobjects/hpentity.h"
#include "logic/shot/shot.h"
#ifndef ROCKET_H
#define ROCKET_H

/**
 * @brief
 *
 */
class Rocket : public HPEntity
{
protected:
    //Velocidad en el eje X
    int _Vx; /**< TODO */
    //Velocidad en el eje Y
    int _Vy; /**< TODO */
public:
    static const int ROCKET_WIDTH; /**< TODO ancho de la nave*/

    static const int ROCKET_HEIGHT; /**< TODO alto de la nave*/

    static const int MAX_HP; /**< TODO vida maxima de las naves*/

    static const int ENEMY_MAX_HP; /**< TODO vida maxima de los enemigos*/


    static const int ROCKET_VELOCITY; /**< TODO velocidad del las naves*/

    /**
     * @brief Constructor solicita la vida que tendra la nave, y el rectagulo donde se definira su geometria
     * y ubicacion
     *
     * @param pRectangle
     * @param pMaxHp
     */
    Rocket(QRect pRectangle, int pMaxHp);
    /**
     * @brief Actualiza la posicion de la nave segun la velocidad de este
     *
     */
    void update();
    /**
     * @brief Setea la velocidad en el eje x
     *
     * @param pXVelocity la nueva
     */
    void setXVelocity(int pXVelocity);
    /**
     * @brief Setea la velocidad en el eje y
     *
     * @param pYVelocity nueva velocidad en el ele y
     */
    void setYVelocity(int pYVelocity);

    /**
     * @brief obtiene la velocidad en el eje x
     *
     * @return int velocidad en el eje x
     */
    int getXVelocity() const;

    /**
     * @brief obtiene la velocidad en el eje y
     *
     * @return int velocidad en el eje y
     */
    int getYVelocity() const;

    /**
     * @brief crea un disparo en la posicion frontal de la nave, este metodo es virtual por lo que se vera
     * sujeto segun la implementacion que se le de
     *
     * @return Shot
     */
    virtual Shot* shoot() = 0;
    /**
     * @brief Liberador de memeoria
     *
     */
    virtual ~Rocket();
};

#endif // ROCKET_H
