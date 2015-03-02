#include "logic/rocket/enemyrocket.h"
#ifndef MOVILENEMYROCKET_H
#define MOVILENEMYROCKET_H

/**
 * @brief Es un clase de nave enemiga que se mueve en linea recta y tambien horizontalmente
 *
 */
class MovilEnemyRocket:public EnemyRocket
{
public:
    /**
     * @brief Es el metodo constructor contiene las mismas caracteristicas que el constructor de
     * @link{EnemyRocket::EnemyRocket()}
     *
     * @param pRectangle es el rectangulo que ubica a la nave y le da dimensiones
     * @param pMaxHp es el numero que representa la maxima cantidad de vida de la nave
     */
    MovilEnemyRocket(QRect pRectangle, int pMaxHp);
    /**
     * @brief Obtiene el tipo de nave en este caso retorna que es un tipo de nave MovilEnemyRocket
     *
     * @return @link{EnemyRocket::MOVIL_ENEMY_ROCKET}
     */
    int getEnemyType();
    /**
     * @brief Actualiza la nave moviendose segun se le indique su velocidad
     *
     */
    void update();
    /**
     * @brief Destructor virtual de la clase
     *
     */
    virtual ~MovilEnemyRocket(){}
};

#endif // MOVILENEMYROCKET_H
