#include "enemyredplane.h"
#include "../helper/gameMainHelper.h"
#include "../manager/bulletManager.h"
EnemyRedPlane::EnemyRedPlane(const PlaneProperty &data)
	: PlaneBase(data)
{
	initWithPropetyData(data);
}
EnemyRedPlane * EnemyRedPlane::createWithPropetydata(const PlaneProperty & prodata)
{
	EnemyRedPlane *plane = new EnemyRedPlane(prodata);
	plane->initWithSpFrameName(prodata.texturename);
	return plane;
}
bool EnemyRedPlane::initWithSpFrameName(const string spframename)
{
	PlaneBase::initWithSpFrameName(spframename);
	return true;
}
bool  EnemyRedPlane::initWithPropetyData(const PlaneProperty &data)
{
	mBulletInternal = 1.0f;
	mIsShow = false;
	return true;
}

void EnemyRedPlane::update(float dt)
{
	CCLog("EnemyRedPlane::updata");
	checkPosition(dt);
	if(isVisible())
	{
		checkFire(dt);
	}
}
void EnemyRedPlane::checkPosition(float dt)
{
	setPositionY (getPositionY()-mSpeed);
}
void EnemyRedPlane::checkFire(float dt)
{
	mBulletInternal -=dt;
	if(mBulletInternal < 0)
	{
		mBulletInternal =1.0f;
		BulletManager::getInstance()->createBullet(BulletType::BULLET_ENEMY_SAMLL1, getPosition(),GameMainHelper::getInstance()->getHeroGlobalPos());
	}
}
