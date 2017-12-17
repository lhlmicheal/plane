#include "weaponbeline.h"
#include "../manager/bulletManager.h"
#include "../manager/audioManager.h"
#include "../helper/gameMainHelper.h"
int WeaponBeLine::Lie[4] = {2, 3, 4, 6};
CCPoint WeaponBeLine::HangPosXY[4][6] = {
	{ccp(-0.5,0),ccp(0.5,0)},
	{ccp(-1.0,0),ccp(0,0),ccp(1.0,0)},
	{ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0)},
	{ccp(-2.5,0),ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0),ccp(2.5,0)}
};
WeaponBeLine::WeaponBeLine()
{
	initWeaponData();
}
WeaponBeLine::~WeaponBeLine()
{
}
void WeaponBeLine::initWeaponData()
{
	timeCount = 0.5f;//行时间间隔
	bulletLv = 0;
	interfal = 20.0f;
	AudioManager::getInstance()->proLoadEffect(EFFECT_BULLET);
	for(int  i= 0;i<4;i++)
	{
		for(int j = 0 ;j<6;j++)
		{
			WeaponBeLine::HangPosXY[i][j].x = WeaponBeLine::HangPosXY[i][j].x*interfal;
		}
	}
}

void WeaponBeLine::updata(float dt)
{
	WeaponBasic::updata(dt);
	if(timeCount > 0)
	{
		timeCount -=dt;
		return;
	}
	timeCount = 0.5f;
	Point heroPos = belongplane->getPosition()+ccp(0,belongplane->getContentSize().height/2);

	for(int m = 0;m<WeaponBeLine::Lie[bulletLv];m++)
	{
		firePos.x = WeaponBeLine::HangPosXY[bulletLv][m].x+heroPos.x;
		firePos.y = WeaponBeLine::HangPosXY[bulletLv][m].y+heroPos.y;
		BulletManager::getInstance()->createBullet(BulletType::BULLET_PLAYER_BELINE,firePos,0);
	}
	AudioManager::getInstance()->playEffect(EFFECT_BULLET);
	
}