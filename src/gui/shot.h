#include "hpentity.h"
#ifndef SHOT_H
#define SHOT_H
class Shot: public Renderizable
{
public:
    virtual void demage(HPEntity *pEntity)=0;
    virtual bool isUefulShot()=0;
    virtual void getType()=0;
    virtual ~Shot();
};
#endif // SHOT_H
