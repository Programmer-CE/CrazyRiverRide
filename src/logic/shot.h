#include "gameobject.h"
#include "hpentity.h"
#ifndef SHOT_H
#define SHOT_H
class Shot: public GameObject
{
public:
    virtual void demage(HPEntity *pEntity)=0;
    virtual bool isUsefulShot()=0;
    virtual void getType()=0;
    virtual ~Shot(){}
};
#endif // SHOT_H