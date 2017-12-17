#include "bulletbeline.h"
#include "../definedata/globalData.h"
BulletBeLine::BulletBeLine(const BulletProperty &data):BulletBase(data)
{
}

BulletBeLine * BulletBeLine::createWithProptyData(const BulletProperty &data)
{
	BulletBeLine *bullet = new BulletBeLine(data);
	bullet->initWithSpriteFrameName(data.picname);
	return bullet;
}
bool BulletBeLine::initWithSpriteFrameName(const std::string &framename)
{
	BulletBase::initWithSpriteFrameName(framename);
	return true;
}

void BulletBeLine::update(float dt)
{
	if(!isShow)
	{	
		setVisible(isShow);
		return;
	}
	checkPos(dt);
}
 void BulletBeLine::checkPos(float dt)
 {
	float xiebian_dis = speed ;
	int angle = abs(rotate);
	Point curPos = getPosition();
	float off_x = xiebian_dis*GlobalData::arrsin[abs(rotate)];
	float off_y = xiebian_dis*GlobalData::arrcos[abs(rotate)];
	if(angle <= 90)
	{
		if(rotate >=  0)
			setPositionX(curPos.x+off_x);
		else
			setPositionX(curPos.x - off_x);
		setPositionY(curPos.y+off_y);
	}
 }