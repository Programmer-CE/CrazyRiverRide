#include "qrect.h"
#include <string>

#ifndef RENDERIZABLE_H
#define RENDERIZABLE_H


using namespace std;

/**
 * @brief Es el objeto principal del programa contiene todas las abstracciones posibles y pensadas por los
 * programadores que trabajaron en ella. El objetivo de esta clase es abstraer la mayoria de las operaciones
 * basicas y comunes entre objetos que contengan rectangulos y deban verificar si colisionan, no olvidando
 * la caracteristica basica de los objetos de este juego,, la tendencia a estar en movimiento, a ser
 * DINAMICOS. De esta clase derivan un monton, y son pocas en comparacion a su utilidad
 *
 */
class GameObject
{
protected:
    QRect _Rectangle; /**< TODO Es el rectangulo que posee las coordenadas y dimensiones del objeto*/
    string _Id; /**< TODO es el identificador unico de cada objeto se pensaba usar en versiones pasadas, ahora es obsoleto*/
    static int _Serial; /**< TODO */
    /**
     * @brief Se encarga de mover el objeto desde la direccion de donde esta, no se encarga de mover el objeto
     * a un punto especifico, si no, de la posicion de la que se encuentra, moverlo lo que se desea
     * en el eje y como en el x.
     *
     * @param pX es la cantidad de pixeles que se quiere mover el objeto en el eje x desde la posicion en
     * la que se encuentra
     * @param pY es la cantidad de pixeles que se quiere mover el objeto en el eje y desde la posicion en
     * la que se encuentra
     */
    void moveInPlace(int pX,int pY);
public:
    /**
     * @brief Es el constructor de la clase es encarga de asignar un rectangulo al objeto que se
     * va a instanciar con este metodo.
     *
     * @param pRect el rectangulo que desea asignarse al objeto que desea crearse con este constructor
     */
    GameObject(QRect pRect);
    /**
     * @brief Es el constructor de copia
     *
     * @param go es el objeto que desea copiarse
     */
    GameObject(GameObject& go);
    /**
     * @brief obtiene una copia del rectangulo contenido en esta clase
     *
     * @return QRect el rectangulo del objeto
     */
    virtual QRect getRect();
    /**
     * @brief Verifica si un GameObject esta colisionando con otro
     *
     * @param _otherRenderizable el otro  objeto para verificar que se colisione
     * @return true si colisionan
     */
    virtual bool isCollide(GameObject *_otherRenderizable);
    /**
     * @brief Actualiza el objeto, es un metodo abstracto, y debe ser implementado por sus clases hijas
     *
     */
    virtual void update() = 0;
    /**
     * @brief Obtiene el ID unico del objeto
     *
     * @return string el id del objeto de juego
     */
    virtual string getId();
    /**
     * @brief obtiene el alto del objeto de juego
     *
     * @return int el alto del objeto del juego
     */
    virtual int getHeight()const;
    /**
     * @brief o¡obtiene el ancho del objeto de juego
     *
     * @return int el ancho del objeto de juego
     */
    virtual int getWidth()const;
    /**
     * @brief Obtiene la posicion en el eje X del objeto de juego
     *
     * @return int las posicion en x
     */
    virtual int getX()const;
    /**
     * @brief Obtiene la posicion en el eje y del objeto de juego
     *
     * @return int la posicion en el eje y
     */
    virtual int getY()const;
    /**
     * @brief Destructor de la clase
     *
     */
    virtual ~GameObject();
};

#endif // RENDERIZABLE_H
