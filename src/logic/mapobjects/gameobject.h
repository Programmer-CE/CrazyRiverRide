#include "qrect.h"
#include <string>

#ifndef RENDERIZABLE_H
#define RENDERIZABLE_H


using namespace std;

class GameObject
{
protected:
    QRect _Rectangle;
    string _Id;
    static int _Serial;
    void moveInPlace(int pX,int pY);
public:
    GameObject(QRect pRect);
    GameObject(GameObject& go);
    virtual QRect getRect();
    virtual bool isCollide(GameObject *_otherRenderizable);
    virtual void update() = 0;
    virtual string getId();
    virtual int getHeight()const;
    virtual int getWidth()const;
    virtual int getX()const;
    virtual int getY()const;
    virtual ~GameObject();
};

#endif // RENDERIZABLE_H
