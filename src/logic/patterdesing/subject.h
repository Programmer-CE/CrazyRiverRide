#include "observer.h"
#ifndef SUBJECT_H
#define SUBJECT_H

/**
 * @brief Es la clase Subject que se suscribe a un objeto de tipo observer y envia las notificaciones
 * necesarias
 *
 */
class Subject
{
public:
    /**
     * @brief Es el metodo constructor por defecto
     *
     */
    Subject();

    /**
     * @brief agrega al observador para notificarle cambios
     * @param pObserver
     */
    virtual void setObserver(Observer *pObserver) = 0;
    /**
     * @brief
     *
     */
    virtual void notifyAll() = 0;
};

#endif // SUBJECT_H
