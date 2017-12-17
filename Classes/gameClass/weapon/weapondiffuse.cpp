#include "weapondiffuse.h"
#include "../manager/bulletManager.h"
#include "../manager/audioManager.h"
int WeaponDiffUse::Lie[4] = {2,3,4,6};
Point WeaponDiffUse::HangPosXY[4][6] = {
	{ccp(-0.5,0),ccp(0.5,0)},
	{ccp(-1.0,0),ccp(0,0),ccp(1.0,0)},
	{ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0)},
	{ccp(-2.5,0),ccp(-1.5,0),ccp(-0.5,0),ccp(0.5,0),ccp(1.5,0),ccp(2.5,0)}
};
int WeaponDiffUse::HangRotate[4][6]={{0,0},{-30,0,30},{-60,-30,30,60},{-60,-30,0,0,30,60}};
WeaponDiffUse::WeaponDiffUse()
{
	initWeaponData();
}
WeaponDiffUse::~WeaponDiffUse()
{
	
}
void WeaponDiffUse::initWeaponData()
{
	timeCount = 0.1f;//行时间间隔
	bulletLv = 0;
	interfal = 20.0f;
	AudioManager::getInstance()->proLoadEffect(EFFECT_BULLET);
}

void WeaponDiffUse::updata(float dt)
{
	WeaponBasic::updata(dt);
	if(timeCount > 0)
	{
		timeCount -=dt;
		return;
	}
	timeCount = 0.1f;
	AudioManager::getInstance()->playEffect(EFFECT_BULLET);
	Point heroPos = belongplane->getPosition()+ccp(0,belongplane->getContentSize().height/2);
	for(int m = 0;m<WeaponDiffUse::Lie[bulletLv];m++)
	{
		firePos.x = WeaponDiffUse::HangPosXY[bulletLv][m].x*interfal+heroPos.x;
		firePos.y = WeaponDiffUse::HangPosXY[bulletLv][m].y+heroPos.y;

		 BulletManager::getInstance()->createBullet(BulletType::BULLET_PLAYER_DIFFUSE,firePos,WeaponDiffUse::HangRotate[bulletLv][m]);
	}
}