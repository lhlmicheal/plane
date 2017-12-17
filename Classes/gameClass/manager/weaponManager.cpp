#include "weaponManager.h"
#include "../weapon/weapondiffuse.h"
#include "../weapon/weaponbeline.h"
#include "../weapon/weaponEneSma2.h"
#include "../weapon/weaponEneSma3.h"
#include "../weapon/weaponEneSma4.h"
#include "../weapon/weaponEneSma5.h"
static WeaponManager* _weapon_manager = NULL;
WeaponManager* WeaponManager::getInstance()
{
	if(_weapon_manager == NULL)
	{
		_weapon_manager = new WeaponManager();
		return _weapon_manager;
	}
	return _weapon_manager;
}
WeaponBasic * WeaponManager::creatWeapon(int weap_kind)
{
	WeaponBasic *weapon = NULL;
	switch (weap_kind)
	{
		case WeaponType::WEAPON_DIFFUSE:
		{
			weapon = new WeaponDiffUse();
		}
		case WeaponType::WEAPON_BELINE:
		{
			weapon = new WeaponBeLine();
		}
		break;
		default:
		break;
	}
	return weapon;
}