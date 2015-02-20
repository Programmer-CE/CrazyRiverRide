#include "renderizable.h"

void Renderizable::moveInPlace(int pX,int pY){
    _Rectangle.setX(_Rectangle.x()+pX);
    _Rectangle.setY(_Rectangle.x()+pY);
}

QRect Renderizable::getRect(){
    return _Rectangle;
}

bool Renderizable::isCollide(Renderizable *_otherRenderizable){
    return _Rectangle.intersects(_otherRenderizable->getRect());
}
