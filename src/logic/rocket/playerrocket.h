#include "rocket.h"
#include "logic/shot/shotmanager.h"
#ifndef PLAYERROCKET_H
#define PLAYERROCKET_H

/**
 * @brief Es la clase que representa la nave del jugador
 *
 */
class PlayerRocket:public Rocket
{
    ShotManager *_ShotManager; /**< TODO Es el manejador de disparos, se encargada de administrar los disparos, mientras utiliza OOP a su favor*/
    int _Combustible; /**< TODO Es la cantidad de combustible del nave del jugador*/
    int _SleepTimeToDecreaseCombustible; /**< TODO Es la cantidad de tiempo con la que decrece el combustible de esta nave*/
public:
    static const int COMBUSTIBLE; /**< TODO Constante que representa la cantidad maxima del combustible*/
    static const int SLEEP_TIME_TO_DECREASE_COMBUSTIBLE; /**< TODO es el tiempo de espera para que se puede disminuir el combustible en uno*/
    /**
     * @brief Constructor de la clase
     *
     * @param pRectangle rectangulo que representa el tamaño y posicion de la nave jugador
     * @param pMaxHp es la cantidad maxima de vida
     * @see{HPEntity::HPEntity()}
     */
    PlayerRocket(QRect pRectangle, int pMaxHp);
    /**
     * @brief Busca la siguiente municion para disparar, entre tipo liear, difusion, mayhem
     *
     */
    void nextMunition();
    /**
     * @brief Agrega municiones a la municion actual
     *
     * @param pMunition es la cantidad de munion a agregar
     */
    void addMunition(int pMunition);
    /**
     * @brief Agrega una cantidad de combustible al jugador
     *
     * @param pCombustuble es la cantidad de combustible por agregar
     */
    void addCombustible(int pCombustuble);
    /**
     * @brief obtiene la cantidad concurrente de combustible de la nave jugador
     *
     * @return int la cantidad actual de combustible
     */
    int getCombustible();
    /**
     * @brief Obtiene la cantidad de municion actual, del tipo de municion que en ese momento se este usando
     *
     * @return int la cantidad de municion de la municion actual
     */
    int getMunitions();
    /**
     * @brief Retorna el tipo de municion definida por @link{Shot::LINEAR_SHOT}, @link{Shot::ANGLE_SHOT}
     * y @link{Shot::MAYHEM_SHOT}
     *
     * @return int cualquiera de las constantes anteorior mente citada
     */
    int getMunitionType();
    /**
     * @brief Actualiza la nave y le quita combustible ademas de actualizar sus coordenadas
     *
     */
    void update();
    /**
     * @brief Crea un disparo, puede ser cualquier tipo de dispar, pero por medio del paradirma de orientacion
     * a objetos todo se resuelve en una sola clase. El disparo es de memoria dinamica por lo que el hay
     * liberar la memoria cuando  este ya no se ocupe
     *
     * @return Shot un puntero a un objeto de tipo Shot alojado en el heap
     */
    Shot* shoot();
    /**
     * @brief Destructor virtual
     *
     */
    virtual ~PlayerRocket();
};

#endif // PLAYERROCKET_H
