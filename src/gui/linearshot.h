#include "shot.h"
#include "renderizable.h"
#ifndef LINEARSHOT_H
#define LINEARSHOT_H
class LinearShot : public Shot
{
protected:
    int _DireccionY;
    int _VelocityY;
    bool __IsTouched;
public:
    void LinearShot(bool _toUp);
    bool isUsefulShot()=0;
    bool isCollide(Renderizable *otherRenderizable);
    void update();

    virtual ~LinearShot();
};
#endif // LINEARSHOT_H
