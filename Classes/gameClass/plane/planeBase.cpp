#include "planeBase.h"
#include "../helper/gameMainHelper.h"

PlaneBase::PlaneBase(const PlaneProperty &data)
{
	mPropertyData = data;
	mType = mPropertyData.type;
	mLife = mPropertyData.hp;
	mSpeed = mPropertyData.speed;
	mIsShow = false;
	mStartPos = Point::ZERO;
	mScore = mPropertyData.score;
	mWeaponTag = mPropertyData.weaponTag;
	mWeaponLevel = 0;
}

PlaneBase::PlaneBase(){
	 mType = -1;
	 mLife = 0;
	 mSpeed = 0;

	 mIsShow = false;
	 mStartPos = Point::ZERO;
	 mScore = 0;
	 mWeaponTag = -1;
	 mWeaponLevel = 0;
}

bool PlaneBase::initWithSpFrameName(const string framename)
{
	CCSprite::initWithSpriteFrameName(framename);
	return true;
}

bool PlaneBase::isDead()
{
	if(mLife <= 0) 
		return true;
	return false;
}

void PlaneBase::resetLife(int life)
{
	this->mLife = life;
}

void PlaneBase::resetShowData(const Point &pos, float hp)
{
	resetProperty();
	mStartPos = pos;
	mLife = hp;
	mIsShow = true;
	setPosition(mStartPos);
	setVisible(mIsShow);
}
void PlaneBase::resetProperty()
{
	mType = mPropertyData.type;
	mLife = mPropertyData.hp;
	mSpeed = mPropertyData.speed;
	mScore = mPropertyData.score;
	mWeaponTag = mPropertyData.weaponTag;
}
void PlaneBase::setHide()
{
	mIsShow= false;
	setVisible(mIsShow);
}

bool PlaneBase::isShowing()
{
	return mIsShow;
}

void PlaneBase::update(float dt)
{
	CCLog("PlaneBase::updata");
}

int PlaneBase::type()
{
		return mType;
}

void PlaneBase::destory()
{
	setHide();
	GameMainHelper::getInstance()->initBoom( getPosition(),1);
	GameMainHelper::getInstance()->changeScore(this->mScore);
	GameMainHelper::getInstance()->removeEnemy(this);
}

void PlaneBase::reduceLife(int des)
{
	mLife -=des;
	if(isDead()) 
	{
		destory();
	}
}