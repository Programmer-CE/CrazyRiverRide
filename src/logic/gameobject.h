#include "qrect.h"
#ifndef RENDERIZABLE_H
#define RENDERIZABLE_H

class GameObject
{
protected:
    QRect _Rectangle;
public:
    virtual void update() = 0;
    void moveInPlace(int pX,int pY);
    QRect getRect();
    bool isCollide(GameObject *_otherRenderizable);
    int getX()const;
    int getY()const;
    int getHeight()const;
    int getWidth()const;
    virtual ~GameObject();
};

#endif // RENDERIZABLE_H
