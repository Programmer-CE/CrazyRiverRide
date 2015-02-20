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
    virtual void LinearShot(bool _toUp)=0;
    virtual bool isUsefulShot()=0;
    virtual bool isCollide(Renderizable *otherRenderizable)=0;
    virtual void update()=0;

    virtual ~LinearShot();
}
#endif // LINEARSHOT_H