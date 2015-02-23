#include "shot.h"
#include "gameobject.h"
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
    void update();
    virtual ~LinearShot();
};
#endif // LINEARSHOT_H
