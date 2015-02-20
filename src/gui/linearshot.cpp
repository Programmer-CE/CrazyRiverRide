#include"linearshot.h"


void LinearShot::LinearShot(bool _toUp)
{
    _DireccionY = _toUp? -1 : 1;
    _VelocityY = 0;
}
bool LinearShot::isUsefulShot()
{
    // Agregar posterior al area de juego.

}
bool LinearShot:: isCollide(Renderizable *otherRenderizable)
{
    return otherRenderizable->getRect().intersects(this->getRect());
}
