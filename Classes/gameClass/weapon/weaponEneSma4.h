#ifndef _weapon_EneSmal4_h
#define _weapon_EneSmal4_h

#include "weaponBasic.h"
class WeaponEneSmall4:public WeaponBasic
{
public:
	WeaponEneSmall4();
	~WeaponEneSmall4();

	static int Lie[4];
	static CCPoint HangPosXY[4][6];
	static int HangRotate[4][6];

	float timeCount;
	int bulletLv;
	float interfal;
	virtual void setFirePos(Point pos);
	void initWeaponData();
	virtual void updata(float dt);
	
};
#endif