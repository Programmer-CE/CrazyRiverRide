#include "shot.h"
#include "gameobject.h"
#ifndef LINEARSHOT_H
#define LINEARSHOT_H
class LinearShot : public Shot
{
protected:
    int _DireccionY;
    int _VelocityY;
    bool __IsTouched;
public:
    LinearShot(bool _toUp);
    bool isUsefulShot()=0;
    bool isCollide(GameObject *otherRenderizable);
    void update();
    virtual ~LinearShot();
};
#endif // LINEARSHOT_H
