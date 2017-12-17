#include "enemysmallplane.h"
#include "../helper/gameMainHelper.h"
#include "../manager/bulletManager.h"
EnemySmallPlane::EnemySmallPlane(const PlaneProperty &data)
	: PlaneBase(data)
{
	initWithPropetyData(data);
}
EnemySmallPlane * EnemySmallPlane::createWithPropetydata(const PlaneProperty & prodata)
{
	EnemySmallPlane *plane = new EnemySmallPlane(prodata);
	plane->initWithSpFrameName(prodata.texturename);
	return plane;
}
bool EnemySmallPlane::initWithSpFrameName(const string spframename)
{
	PlaneBase::initWithSpFrameName(spframename);
	return true;
}
bool  EnemySmallPlane::initWithPropetyData(const PlaneProperty &data)
{
	mBulletInternal = 1.0f;
	mIsShow = false;
	return true;
}

void EnemySmallPlane::update(float dt)
{
	checkPosition(dt);
	if(isVisible())
	{
		checkFire(dt);
	}
}
void EnemySmallPlane::checkPosition(float dt)
{
	setPositionY (getPositionY()-mSpeed);
}
void EnemySmallPlane::checkFire(float dt)
{
	mBulletInternal -=dt;
	if(mBulletInternal < 0)
	{
		mBulletInternal =1.0f;
		BulletManager::getInstance()->createBullet(mWeaponTag, getPosition(),GameMainHelper::getInstance()->getHeroGlobalPos());
	}
}
