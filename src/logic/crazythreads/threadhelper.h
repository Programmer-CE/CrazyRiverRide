#ifndef THREADHELPER_H
#define THREADHELPER_H

#include <QObject>

/**
 * @brief Es un ayudante del @link{GameLoop}
 * Este se comunica con la interfaz grafica del juego debido a que la ventana solo acepta objetos pertenecientes
 * a qt y por ende esta clase hereda a QObject
 */
class ThreadHelper : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Es el metodo constructor se encarga de inicalizar el objeto en cuestion
     *
     * @param parent
     */
    explicit ThreadHelper(QObject *parent = 0);

signals:
    /**
     * @brief es un signal que se envia a la ventana, pues la ventana del qt detecta cuando se esta haciendo
     * un repaint recursivo, la unica forma de trabajarlo es mediante de signals y slots,
     * para mas informacion mirar e siguiente link
     * https://bugreports.qt.io/browse/QTBUG-13641
     *
     */
    void renderGame();
public slots:

};

#endif // THREADHELPER_H
