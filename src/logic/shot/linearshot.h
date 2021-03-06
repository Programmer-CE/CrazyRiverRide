#include "shot.h"
#include "logic/mapobjects/gameobject.h"
#ifndef LINEARSHOT_H
#define LINEARSHOT_H
class LinearShot : public Shot
{
protected:
    int _VelocityY;
    bool _IsTouched;
public:
    LinearShot(QRect pRectangle,bool pToUp, int pDamage);
    bool isUsefulShot(QRect pArea);
    bool isCollide(GameObject *otherRenderizable);
    int getXVelocity();
    int getYVelocity();
    int getType();
    void update();
    virtual ~LinearShot();
};
#endif // LINEARSHOT_H
