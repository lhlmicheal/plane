#ifndef ENEMY_YELLOW_H
#define ENEMY_YELLOW_H
#include "planeBase.h"
#include "../definedata/planepropertydata.h"
#include "../weapon/weaponBasic.h"
class EnemySmallPlane:public PlaneBase
{
public:
	EnemySmallPlane(const PlaneProperty &data);
	static EnemySmallPlane * create(const std::string & filename);
	static EnemySmallPlane * createWithSpriteFrame(SpriteFrame *spriteFrame);
	static EnemySmallPlane * createWithPropetydata(const PlaneProperty& data);
	bool  initWithPropetyData(const PlaneProperty &data);
	virtual bool initWithSpFrameName(const string spframename);
public:
	//µÐ»úÃ»ÓÐÎäÆ÷¸ÅÄî
	virtual void update(float dt);
	void checkPosition(float dt);
	void checkFire(float dt);
public:
	float mBulletInternal;
};
#endif