#include "weaponEneSma3.h"
#include "../manager/bulletManager.h"
#include "../manager/audioManager.h"
int WeaponEneSmall3::Lie[4] = {2,3,4,6};
CCPoint WeaponEneSmall3::HangPosXY[4][6] = {
	{ccp(-0.5,0),ccp(0.5,0)},
	{ccp(-1.0,0),ccp(0,0),ccp(1.0,0)},
	{ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0)},
	{ccp(-2.5,0),ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0),ccp(2.5,0)}
};
int WeaponEneSmall3::HangRotate[4][6]={{0,0},{-30,0,30},{-60,-30,30,60},{-60,-30,0,0,30,60}};
WeaponEneSmall3::WeaponEneSmall3()
{
	initWeaponData();
}
WeaponEneSmall3::~WeaponEneSmall3()
{
	
}
void WeaponEneSmall3::setFirePos(Point pos)
{
	firePos = pos;
}
void WeaponEneSmall3::initWeaponData()
{
	timeCount = 0.5f;//��ʱ����
	bulletLv = 1;
	interfal = 20.0f;
	AudioManager::getInstance()->proLoadEffect(EFFECT_BULLET);
	for(int  i= 0;i<4;i++)
	{
		for(int j = 0 ;j<6;j++)
		{
			WeaponEneSmall3::HangPosXY[i][j].x = WeaponEneSmall3::HangPosXY[i][j].x*interfal;
		}
	}
}

void WeaponEneSmall3::updata(float dt)
{
	//CCLog("WeaponTest::Updata");
	WeaponBasic::updata(dt);
	for(int m = 0;m<WeaponEneSmall3::Lie[bulletLv];m++)
	{
		CCPoint heroPos = belongplane->getPosition()+ccp(0,belongplane->getContentSize().height/2);
		CCLog("WeaponTest.heroPos.x=%f,y=%f",heroPos.x,heroPos.y);
		CCPoint pos = WeaponEneSmall3::HangPosXY[bulletLv][m]+heroPos;

		//BulletManager::getInstance()->createBullet(WeaponType::WEAPON_ENEMY_SAMLL_3,firePos,WeaponEneSmall3::HangRotate[bulletLv][m]);
	}
	AudioManager::getInstance()->playEffect(EFFECT_BULLET);
	
}