#ifndef _weapon_EneSmal3_h
#define _weapon_EneSmal3_h

#include "weaponBasic.h"
class WeaponEneSmall3:public WeaponBasic
{
public:
	WeaponEneSmall3();
	~WeaponEneSmall3();

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