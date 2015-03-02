#include "crazythread.h"
#include "logic/kernelgame.h"
#include "logic/crazythreads/threadhelper.h"
#ifndef GAMELOOP_H
#define GAMELOOP_H

/**
 * @brief Es la clase que se encarga de controlar el pintado de la ventana del juego seccionandolo en
 * frame por segundo, especificamente 24 fps, la clase regula el pintado y la ejecucion de las actualizaciones
 * del juego mismo
 *
 */
class GameLoop:public CrazyThread
{
    KernelGame * _KernelGame; /**< TODO es en donde es contenida la logica*/
    ThreadHelper * guiConector; /**< TODO es una variable que se conecta con el la ventana para enviarle signals*/
protected:
    /**
     * @brief Es el metodo a sobrescribir de su clase padre
     * @link{CrazyThread}
     * El metodo se encarga de regular las actualizaciones logicas dentro del juego ademas de enviar signal
     * para que la ventana pueda pintar estas actualizacion
     */
    void internalRun();
public:
    /**
     * @brief Es el constructor de la clase
     *
     * @param pKernelGame es la variable que contiene la logica y la cual sera el punto centra de este thread
     */
    GameLoop(KernelGame *pKernelGame);
    /**
     * @brief Metodo virtual destructor, se encarga de detener el thread si este no ha sido detenido para
     * evitar problemas en tiempo de ejecucion
     *
     */
    virtual ~GameLoop();
    /**
     * @brief retorna un puntero a la objeto que se encarga de conectarse con la logica
     *
     * @return ThreadHelper el puntero que se encarga de conectarse con la logica
     */
    ThreadHelper* getGuiConector() const;
};

#endif // GAMELOOP_H
