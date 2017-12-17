#ifndef _PLANT_FACTORY_H
#define _PLANT_FACTORY_H
#include "factoryBase.h"
#include "../plane/planeBase.h"
enum planeType
{
	UNDEFINE_PLANE = 0,
	//small plane type
	ENEMY_YELLOW = 1,
	ENEMY_WHITE,
	ENEMY_RED,
	ENEMY_GREEN,
	ENEMY_BLUE,
	//middle plane type
	MIDDLE_ATTACK = 6,
	MIDDLE_FAST,
	MIDDLE_HEAVY,
	//boss plane type
	BOSS_CHART1 = 9,
	BOSS_CHART2,
	BOSS_CHART3,
	BOSS_CHART4
};
class PlaneFactory:public FactoryBase<PlaneBase*>
{
public:
	virtual PlaneBase* CreateObjectFactory(int type);
};
#endif