#ifndef  WEAPON_BELINE_H
#define WEAPON_BELINE_H

#include "weaponBasic.h"
class WeaponBeLine:public WeaponBasic
{
public:
	WeaponBeLine();
	~WeaponBeLine();

	static int Lie[4];
	static CCPoint HangPosXY[4][6];

	float timeCount;
	int bulletLv;
	float interfal;

	void initWeaponData();
	void updata(float dt);
	
};
#endif