#include "bulletdiffuse.h"
#include "../definedata/globalData.h"
BulletDiffUse::BulletDiffUse(const BulletProperty &data):BulletBase(data)
{
}

BulletDiffUse * BulletDiffUse::createWithProptyData(const BulletProperty &data)
{
	BulletDiffUse *bullet = new BulletDiffUse(data);
	bullet->initWithSpriteFrameName(data.picname);
	return bullet;
}
bool BulletDiffUse::initWithSpriteFrameName(const std::string &framename)
{
	BulletBase::initWithSpriteFrameName(framename);
	return true;
}

void BulletDiffUse::update(float dt)
{
	if(!isShow)
	{	
		setVisible(isShow);
		return;
	}
	checkPos(dt);
}
 void BulletDiffUse::checkPos(float dt)
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