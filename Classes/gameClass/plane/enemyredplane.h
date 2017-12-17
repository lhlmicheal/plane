#ifndef ENEMY_Red_H
#define ENEMY_Red_H
#include "planeBase.h"
#include "../definedata/planepropertydata.h"
#include "../weapon/weaponBasic.h"
class EnemyRedPlane:public PlaneBase
{
public:
	EnemyRedPlane(const PlaneProperty &data);
	static EnemyRedPlane * create(const std::string & filename);
	static EnemyRedPlane * createWithSpriteFrame(SpriteFrame *spriteFrame);
	static EnemyRedPlane * createWithPropetydata(const PlaneProperty& data);
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