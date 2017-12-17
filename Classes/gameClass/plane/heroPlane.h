#ifndef _HERO_PLANE_H
#define _HERO_PLANE_H
#include "planeBase.h"
#include "../manager/weaponManager.h"
#include "../weapon/weaponBasic.h"
class HeroPlane:public PlaneBase
{
public:
	static HeroPlane * heroPlanecreateWithSpriteFrame(SpriteFrame *spriteFrame);
public:
	void update(float dt);
	void checkWeapon(float dt);
	void initHeroData();
	int weaponLevel();
	void destory();
	void reduceLife(int des);
	int mId;
	void reLive();
	WeaponBasic * mWeapon[2];
	static int HeroPlane::weaponIdArr[3][2][2];
	static int AutoLive;
};
#endif