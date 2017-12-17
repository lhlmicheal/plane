#ifndef _weapon_EneSmal5_h
#define _weapon_EneSmal5_h

#include "weaponBasic.h"
class WeaponEneSmall5:public WeaponBasic
{
public:
	WeaponEneSmall5();
	~WeaponEneSmall5();

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