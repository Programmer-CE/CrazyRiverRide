#include "logic/shot/shot.h"
#include "rocket.h"
#ifndef ENEMYROCKET_H
#define ENEMYROCKET_H

/**
 * @brief Es la clase que filtra a las clases enemigo, es un clasificacion, pero aun asi es muy util como
 * es el caso del uso del metodo shoot que lo implementa de tal forma que todos los enemigos los usen
 *
 */
class EnemyRocket:public Rocket
{
public:
    static const int KAMIKAZE; /**< TODO tipo de nave kamizake */
    static const int MOVIL_ENEMY_ROCKET; /**< TODO tipo de nave movil rocket*/
    /**
     * @brief Es el constructor de las clases enemigas utiliza al igual que su clase padre un
     * rectangulo y un entero para representar su posicion y dimension para el caso de l rectangulo y el
     * emtero representa la cantidad maxima de la nave
     *
     * @param pRectangle Es el rectangulo que representa las dimensiones y la ubicacion de un objeto
     * @param pMaxHp Es el numero que representa la vida maxima de la nave enemiga
     */
    EnemyRocket(QRect pRectangle, int pMaxHp);
    /**
     * @brief Crea un disparo, el disparo es creado de manera dinamica por lo que es responsabilidad del
     * programador borrarlo de memoria
     *
     * @return Shot retorna un puntero aun objeto tipo Shot en el heap
     */
    Shot* shoot();
    /**
     * @brief retorna el tipo de enemigo en el caso, esto retorna una constante que representa ese tipo de
     * nave, el metodo debe implementarse por las clases hijas
     * @return int retorna una constante que representa el tipo de nave
     */
    virtual int getEnemyType() = 0;
    /**
     * @brief El destructor de la clase Nave Enemiga
     *
     */
    virtual ~EnemyRocket();
};

#endif // ENEMYROCKET_H
