#include "logic/mapobjects/hpentity.h"

HPEntity::HPEntity(QRect pRectangle, int pMaxHp):GameObject(pRectangle),_Hp(pMaxHp),_MaxHp(pMaxHp)
{
}

void HPEntity::addHitPoints(int pHp){
    if (pHp+_Hp <= 0)_Hp = 0;
    else if (pHp+_Hp > _MaxHp)_Hp = _MaxHp;
    else _Hp += pHp;
}

bool HPEntity::isDead()const{
    return _Hp == 0;
}

int HPEntity::getHitPoints()const{
    return _Hp;
}

HPEntity::~HPEntity(){
}
