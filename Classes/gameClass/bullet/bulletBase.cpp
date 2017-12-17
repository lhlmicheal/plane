#include "bulletBase.h"
#include "../helper/gameMainHelper.h"
#include "../factory/bulletFactory.h"
BulletBase::BulletBase()
{
	startPos = Point::ZERO;
	 speed = 0;
	 power = 0;
	 type = -1;
	 imageWidth = 0.0f;
	 imageHeight = 0.0f;
	 isAddSheet =false;
	 isShow = false;
	 targetPos = Point::ZERO;
	 rotate = 0;
	 direction = 0;
}
BulletBase::BulletBase(const BulletProperty &data)
{
	mPropertyData = data;
	startPos= Point::ZERO;
	 speed = mPropertyData.speed;
	 power = mPropertyData.power;
	 type = mPropertyData.type;
	 imageWidth = 0.0f;
	 imageHeight = 0.0f;
	 isAddSheet =false;
	 isShow = true;
	 targetPos = Point::ZERO;
	 rotate = 0;
	 direction = rotate;
}

bool BulletBase::initWithSpriteFrameName(const std::string &frameName)
{
	Sprite::initWithSpriteFrameName(frameName);
	return true;
}

void BulletBase::resetShowBulletData(float datarotate,Point firepos)
{
	resetPropetyData();
	startPos= firepos;
	 isShow = true;
	 rotate = datarotate;
	 direction = rotate;
	 this->setPosition(startPos);
	 this->setVisible(isShow);
}
void BulletBase::resetPropetyData()
{
	 speed = mPropertyData.speed;
	 power = mPropertyData.power;
}
void BulletBase::setHide()
{
	isShow = false;
	setVisible(isShow);
}
void BulletBase::update(float dt)
{
	;
}
void BulletBase::checkPos(float dt)
{
	;
}
void BulletBase::connectEnemy()
{
	isShow = false;
	setVisible(isShow);
	GameMainHelper* helper = GameMainHelper::getInstance();
	if(type == BulletType::BULLET_PLAYER_DIFFUSE
		|| type == BulletType::BULLET_PLAYER_BELINE)//Ö÷½Ç×Óµ¯
	{
		helper->removePlayerBullet(this);
	}else
	{
		helper->removeEnemyBullet(this);
	}
}
