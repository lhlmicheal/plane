#ifndef WEAPON_DIFFUSE_H
#define WEAPON_DIFFUSE_H

#include "weaponBasic.h"
class WeaponDiffUse:public WeaponBasic
{
public:
	WeaponDiffUse();
	~WeaponDiffUse();

	static int Lie[4];
	static Point HangPosXY[4][6];
	static int HangRotate[4][6];

	float timeCount;
	int bulletLv;
	float interfal;

	void initWeaponData();
	virtual void updata(float dt);
	
};
#endif