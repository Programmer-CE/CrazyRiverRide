#include "qrect.h"
#include "qpainter.h"
#ifndef RENDERIZABLE_H
#define RENDERIZABLE_H

class Renderizable
{
protected:
    QRect _Rectangle;
public:
    virtual void render(QPainter *pPainter)=0;
    virtual void update() = 0;
    void moveInPlace(int pX,int pY);
    QRect getRect();
    bool isCollide(Renderizable *_otherRenderizable);
};

#endif // RENDERIZABLE_H