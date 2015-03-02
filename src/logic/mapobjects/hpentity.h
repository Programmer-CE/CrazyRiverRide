#include "gameobject.h"
#ifndef HPENTITY_H
#define HPENTITY_H

/**
 * @brief Es una derivacion de la clase @link{GameObject}
 * se encarga de estructurar aun mas el proyecto especializando algunos tipos de GameObject y haciendo
 * que estos tengan controles de vida, las clases que deriven de esta seran las que posean atributos de vida
 *
 */
class HPEntity:public GameObject
{
protected:
    int _Hp; /**< TODO es la vida concurrente de la entidad*/
    int _MaxHp; /**< TODO es la cantidad maxima de vida , la minima es cero*/
public:
    /**
     * @brief Es el metodo constructor se encarga, darle dimensiones y posicion a la entidad con hit points
     * ademas de otorgarle una vida maxima de la entidad.
     *
     * @param pRectangle Es el rectangulo que le dara dimensiones y posicion a la entidad de puntos de vida
     * @param pMaxHp la cantidad de vida maxima de la entidad
     */
    HPEntity(QRect pRectangle, int pMaxHp);

    /**
     * @brief Verifica si la entidad tiene puntos de vida, si esta tiene entonces no esta muerta, eso si
     * la cantidad de vida tiene que ser mayor que cero para que la entidad se considere viva
     *
     * @return true, si la cantidad de vida es menor o igual a cero
     */
    bool isDead()const;
    /**
     * @brief Suma una cantidad de vida a la entidad, si esta cantidad es negativa, entonces le resta vida,
     * en el caso de que sea cero es neutra y la vida de la entidad no se ve afectada, en el caso
     * de que la cantidad es positiva suma los puntos de vida, las sumas y restas se mantienen en el intervalo
     * de cero a la cantidad maxima de vida de la entidad, por lo tanto es un conjunto cerrado de numeros usados
     * dentro de la entidad
     *
     * @param pHp es la cantidad de vida que se le desea sumar o sustraer a la entidad
     */
    void addHitPoints(int pHp = -1);
    /**
     * @brief Obtiene la cantidad de vida concurrente de la entidad de vida.
     *
     * @return int la cantidad de vida de la entidad en la que se invoca esta funcion
     */
    int getHitPoints()const;
    /**
     * @brief Destructor virtual de la clase
     *
     */
    virtual ~HPEntity();
};

#endif // HPENTITY_H
