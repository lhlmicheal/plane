#include "heroPlane.h"

int HeroPlane::weaponIdArr[3][2][2] ={
	{
		{WeaponType::WEAPON_BELINE,WeaponType::WEAPON_DIFFUSE},
		{WeaponType::WEAPON_DIFFUSE,WeaponType::WEAPON_DIFFUSE}
	},
	{
		{WeaponType::WEAPON_DIFFUSE,WeaponType::WEAPON_DIFFUSE},
		{WeaponType::WEAPON_DIFFUSE,WeaponType::WEAPON_DIFFUSE}
	},
	{
		{WeaponType::WEAPON_DIFFUSE,WeaponType::WEAPON_DIFFUSE},
		{WeaponType::WEAPON_DIFFUSE,WeaponType::WEAPON_DIFFUSE}
	}
};
int HeroPlane::AutoLive = 2;
HeroPlane * HeroPlane::heroPlanecreateWithSpriteFrame(SpriteFrame *spriteFrame)
{
	HeroPlane *heroplane = new HeroPlane();
	if(heroplane && spriteFrame && heroplane->initWithSpriteFrame(spriteFrame))
	{
		heroplane->autorelease();
		return heroplane;
	}
	CC_SAFE_DELETE(heroplane);
	return  nullptr;
}
void HeroPlane::initHeroData()
{
	mId = 0;
	mWeaponTag = 0;
	mLife = 90;
	mWeapon[0] =NULL;
	mWeapon[1] =NULL;
	if(mWeapon[0] == NULL)
	{
		mWeapon[0] = WeaponManager::getInstance()->creatWeapon(weaponIdArr[mId][mWeaponLevel][0]);
		mWeapon[0]->equipweapon(this);
	}
}

int HeroPlane::weaponLevel()
{
	return mWeaponLevel;
}
void HeroPlane::update(float dt)
{
	if(!isDead())
	checkWeapon(dt);
}
void HeroPlane::checkWeapon(float dt)
{
	if(mWeapon[0]!= NULL)
	{
		mWeapon[0]->updata(dt);
	}
	if(mWeapon[1]!= NULL)
	{
		mWeapon[1]->updata(dt);
	}
}
void HeroPlane::reduceLife(int des)
{
	mLife -= des;
	if(mLife <= 0 && HeroPlane::AutoLive > 0)
		destory();

}
void HeroPlane::destory()
{
	if(HeroPlane::AutoLive-- > 0)
	{
	Blink *actionBlink = Blink::create(1.5f, 6); 
	DelayTime *actiondelay = DelayTime::create(0.2f);//CallFunc::create(this, callfunc_selector(HeroPlane::reLive))
	Sequence *actionSeq = Sequence::create(actionBlink, actiondelay, nullptr);
	runAction(actionSeq);
	}	
}
void HeroPlane::reLive()
{
	mLife = 100;
	mIsShow = true;
	setVisible(mIsShow);
}