#include "logic/mapobjects/gamemap.h"
#include <cmath>

GameMap::GameMap(QRect pRect,int pVy, int pLimit):GameObject(pRect),_Vy(pVy),_Limit(pLimit)
{

}

void GameMap::update()
{
    if (abs(_Limit)-abs(_Rectangle.y())>0)moveInPlace(0,_Vy);
}
