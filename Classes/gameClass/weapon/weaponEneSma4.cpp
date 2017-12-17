#include "weaponEneSma4.h"
#include "../manager/bulletManager.h"
#include "../manager/audioManager.h"
int WeaponEneSmall4::Lie[4] = {2,3,4,6};
CCPoint WeaponEneSmall4::HangPosXY[4][6] = {
	{ccp(-0.5,0),ccp(0.5,0)},
	{ccp(-1.0,0),ccp(0,0),ccp(1.0,0)},
	{ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0)},
	{ccp(-2.5,0),ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0),ccp(2.5,0)}
};
int WeaponEneSmall4::HangRotate[4][6]={{0,0},{-30,0,30},{-60,-30,30,60},{-60,-30,0,0,30,60}};
WeaponEneSmall4::WeaponEneSmall4()
{
	initWeaponData();
}
WeaponEneSmall4::~WeaponEneSmall4()
{
	
}
void WeaponEneSmall4::initWeaponData()
{
	timeCount = 0.5f;//行时间间隔
	bulletLv = 1;
	interfal = 20.0f;
	AudioManager::getInstance()->proLoadEffect(EFFECT_BULLET);
	for(int  i= 0;i<4;i++)
	{
		for(int j = 0 ;j<6;j++)
		{
			WeaponEneSmall4::HangPosXY[i][j].x = WeaponEneSmall4::HangPosXY[i][j].x*interfal;
		}
	}
}
void WeaponEneSmall4::setFirePos(Point pos)
{
	firePos = pos;
}
void WeaponEneSmall4::updata(float dt)
{
	//CCLog("WeaponTest::Updata");
	WeaponBasic::updata(dt);
	for(int m = 0;m<WeaponEneSmall4::Lie[bulletLv];m++)
	{
		CCPoint heroPos = belongplane->getPosition()+ccp(0,belongplane->getContentSize().height/2);
		CCLog("WeaponTest.heroPos.x=%f,y=%f",heroPos.x,heroPos.y);
		CCPoint pos = WeaponEneSmall4::HangPosXY[bulletLv][m]+heroPos;

		//BulletManager::getInstance()->createBullet(WeaponType::WEAPON_ENEMY_SAMLL_4,firePos,WeaponEneSmall4::HangRotate[bulletLv][m]);
	}
	AudioManager::getInstance()->playEffect(EFFECT_BULLET);
	
}