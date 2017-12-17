#include "bulletsmallenemy.h"
#include "../helper/gameMainHelper.h"
#include "../definedata/globalData.h"
BulletSmallEnemy::BulletSmallEnemy(const BulletProperty &data):BulletBase(data)
{
}
BulletSmallEnemy * BulletSmallEnemy::createWithProptyData(const BulletProperty &data)
{
	BulletSmallEnemy *bullet = new BulletSmallEnemy(data);
	bullet->initWithSpriteFrameName(data.picname);
	return bullet;
}
bool BulletSmallEnemy::initWithSpriteFrameName(const std::string &framename)
{
	BulletBase::initWithSpriteFrameName(framename);
	return true;
}
void BulletSmallEnemy::update(float dt)
{
	if(!isShow)
	{	
		setVisible(isShow);
		return;
	}
	checkPos(dt);
}
 void BulletSmallEnemy::checkPos(float dt)
 {
	 float rot_value = abs(rotate);
	 int rot_ = (int)rot_value;
	 setRotation(rotate);
	 float off_x =0;
	 float off_y = 0;
	 if(rotate > 0)
	 {
		 if(rot_value > 90)
		 {
			 off_x = speed *( abs(GlobalData::arrcos[rot_ -90]) );
			 off_y = speed *( abs(GlobalData::arrsin[rot_ -90]) );
			 setPosition(getPositionX() + off_x,getPositionY()-off_y);
		 }
		 else
		 {
			 off_x = speed *( abs(GlobalData::arrcos[90 - rot_]) );
			 off_y = speed *( abs(GlobalData::arrsin[90 - rot_]) );
			 setPosition(getPositionX() + off_x,getPositionY()+off_y);
		 }
	 }
	 else
	 {
		  if(rot_value > 90)
		 {
			 off_x = speed *(abs (GlobalData::arrcos[rot_ -90]) );
			 off_y = speed *(abs (GlobalData::arrsin[rot_ -90]));
			 setPosition(getPositionX() - off_x,getPositionY()-off_y);
		 }
		 else
		 {
			 off_x = speed *(abs (GlobalData::arrcos[90 - rot_]) );
			 off_y = speed *(abs (GlobalData::arrsin[90 - rot_]) );
			 setPosition(getPositionX() - off_x,getPositionY()+off_y);
		 }
	 }
 }
