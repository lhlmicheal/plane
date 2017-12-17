#ifndef _weaponBasic_h
#define _weaponBasic_h
#include "../plane/planeBase.h"
class WeaponBasic
{
public:
	WeaponBasic(){
	weaponLv = 0;
	belongplane = NULL;
	}
	~WeaponBasic(){}
	virtual void  updata(float dt);

	virtual void equipweapon(PlaneBase* plane) ;
	virtual void unequipWeapon();
	/*virtual void upgrade() = 0;*/
	virtual void upgrade();
	virtual void setFirePos(Point pos);
public:
	int weaponLv;
	PlaneBase *belongplane;
	Point firePos;
};
#endif