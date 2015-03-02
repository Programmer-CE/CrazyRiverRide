#include "gameobject.h"
#ifndef GAMEMAP_H
#define GAMEMAP_H

/**
 * @brief Es el mapa del nivel
 *
 */
class GameMap:public GameObject
{
    int _Vy,_Limit; /**< TODO */
public:
    /**
     * @brief Es el constructor de la clase, da un rectangulo que da la posicion y dimensiones del objeto,
     * tambien la velocidad en el eje Y que se movera el objeto y un limite que le diga hasta que punto llegar
     * en el eje Y
     *
     * @param pRect contiene las dimensiones del objeto a crear
     * @param pVy es la velocidad en el eje Y
     * @param pLimit es el limite hasta el cual se movera el  objeto
     */
    GameMap(QRect pRect,int pVy, int pLimit);
    /**
     * @brief Actualiza la posicion del mapa hasta llegar al limite impuesto
     *
     */
    void update();
};

#endif // GAMEMAP_H
