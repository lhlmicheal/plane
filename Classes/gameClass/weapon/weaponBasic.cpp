#include "weaponBasic.h"
void WeaponBasic::updata(float dt)
{

}
void WeaponBasic::equipweapon(PlaneBase* plane)
{
	belongplane = plane;
}
void WeaponBasic::unequipWeapon()
{
	belongplane = NULL;
}
/*virtual void upgrade() = 0;*/
void WeaponBasic::upgrade()
{
	if(weaponLv <= 4)
	{
		weaponLv++;
	}
}
void WeaponBasic::setFirePos(Point pos)
{
	firePos = pos;
}