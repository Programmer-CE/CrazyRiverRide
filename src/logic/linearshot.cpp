#include"linearshot.h"


LinearShot::LinearShot(bool _toUp)
{
    _DireccionY = _toUp? -1 : 1;
    _VelocityY = 0;
}
bool LinearShot::isUsefulShot()
{
    // Agregar posterior al area de juego.
    return __IsTouched;

}
bool LinearShot::isCollide(GameObject *otherRenderizable)
{
    return otherRenderizable->getRect().intersects(this->getRect());
}

void LinearShot::update()
{

}


LinearShot::~LinearShot()
{
}
