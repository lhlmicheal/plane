#ifndef _weapon_EneSmal2_H
#define _weapon_EneSmal2_H

#include "weaponBasic.h"
class WeaponEneSmall2:public WeaponBasic
{
public:
	WeaponEneSmall2();
	~WeaponEneSmall2();

	static int Lie[4];
	static CCPoint HangPosXY[4][6];
	static int HangRotate[4][6];

	float timeCount;
	int bulletLv;
	float interfal;

	void initWeaponData();
	virtual void updata(float dt);
	virtual void setFirePos(Point pos);
};
#endif