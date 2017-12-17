#ifndef _bullet_manager_h
#define _bullet_manager_h
#include "factoryBase.h"
#include "../bullet/bulletBase.h"
enum BulletType
{
	//small bullet
	BULLET_SMALL_YELLOW = 1,
	BULLET_SMALL_WHITE,
	BULLET_SMALL_RED,
	BULLET_SMALL_GREED,
	BULLET_SMALL_BLUE,
	//middle bullet
	BULLET_MIDDLE_ATTACK,
	BULLET_MIDDLE_FAST,
	BULLET_MIDDLE_HEAVY,
	//boss bullet
	BULLET_BOSS_CHART1, 
	BULLET_BOSS_CHART2, 
	BULLET_BOSS_CHART3, 
	BULLET_BOSS_CHART4, 
	BULLET_BOSS_CHART5,
	//player bullet
	BULLET_PLAYER_DIFFUSE = 100, //扩散的
	BULLET_PLAYER_BELINE = 101, //直线型的
	BULLET_PLAYER_LASER = 102, //激光的
	BULLET_PLAYER_TRACK = 103, //跟踪的
};
class BulletFactory : public FactoryBase<BulletBase*>
{
public:
	BulletFactory(){};
	~BulletFactory(){};
	virtual BulletBase* CreateObjectFactory(int type);
};
#endif