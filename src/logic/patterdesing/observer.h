#include <google/protobuf/message.h>

#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief Es la clase que cumple con el patron de diseño observer
 * Este es el observador al cual se le envian notificaciones y este las interpreta segun la implementacion de
 * la clase hija que sobrescriba el metodo update de esta clase
 *
 */
class Observer
{
public:
    /**
     * @brief El metodo de constructor por defecto
     *
     */
    Observer(){}
    /**
     * @brief Recibe un mensaje mediante el uso de protocol buffers de google
     * Recibe el protocolo, y lo decodifica con la implementacion necesaria que se le de al la clase que
     * sobrescriba este metodo virtual
     *
     * @param pMessage Es el mensaje recibido que es parte de los protocol buffers de google
     */
    virtual void update(google::protobuf::Message *pMessage) = 0;
    /**
     * @brief ~Observer Es el destructor virtual de la clase
     */
    virtual ~Observer(){}
};

#endif // OBSERVER_H
