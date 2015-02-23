#include "gameobject.h"
#include <string>
#include <sstream>


int GameObject::_Serial = 0;

GameObject::GameObject(QRect pRect):_Rectangle(pRect){
    std::stringstream ss;
    ss << this->_Serial++;
    _Id = string("gameobject@") + ss.str();
}

GameObject::GameObject(GameObject &go): _Rectangle(go._Rectangle)
{
    _Id = go._Id;
}



void GameObject::moveInPlace(int pX,int pY){
    _Rectangle.setX(_Rectangle.x()+pX);
    _Rectangle.setY(_Rectangle.x()+pY);
}


QRect GameObject::getRect(){
    return _Rectangle;
}

bool GameObject::isCollide(GameObject *_otherRenderizable){
    return _otherRenderizable && _Rectangle.intersects(_otherRenderizable->getRect());
}

string GameObject::getId(){
    return _Id;
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
