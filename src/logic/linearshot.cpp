#include"linearshot.h"


LinearShot::LinearShot(QRect pRectangle, bool pToUp, int pDamage):Shot(pRectangle,pDamage)
{
    int direccion = pToUp? -1 : 1;
    _VelocityY = VELOCITY*direccion;
}
bool LinearShot::isUsefulShot(QRect pArea)
{
    // Agregar posterior al area de juego.
    return !_IsTouched && pArea.intersects(this->_Rectangle);

}
bool LinearShot::isCollide(GameObject *otherRenderizable)
{
    if (otherRenderizable){
        _IsTouched = otherRenderizable->getRect().intersects(this->getRect());
        return _IsTouched;
    }
    return false;
}

int LinearShot::getYVelocity()
{
    return _VelocityY;
}

int LinearShot::getXVelocity()
{
    return 0;
}

void LinearShot::update()
{
    moveInPlace(0,_VelocityY);
}


LinearShot::~LinearShot()
{
}
