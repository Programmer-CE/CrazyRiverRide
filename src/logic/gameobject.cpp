#include "gameobject.h"

void GameObject::moveInPlace(int pX,int pY){
    _Rectangle.setX(_Rectangle.x()+pX);
    _Rectangle.setY(_Rectangle.x()+pY);
}

QRect GameObject::getRect(){
    return _Rectangle;
}

bool GameObject::isCollide(GameObject *_otherRenderizable){
    return _Rectangle.intersects(_otherRenderizable->getRect());
}

int GameObject::getX() const
{
    return _Rectangle.x();
}

int GameObject::getY() const
{
    return _Rectangle.y();
}


int GameObject::getHeight() const
{
    return _Rectangle.height();
}

int GameObject::getWidth() const
{
    return _Rectangle.width();
}

GameObject::~GameObject(){}
