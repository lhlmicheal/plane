#ifndef _weaponManager_h
#define _weaponManager_h
#include "cocos2d.h"
USING_NS_CC;
#include "../weapon/weaponBasic.h"
enum WeaponType
{
	WEAPON_DIFFUSE = 1,
	WEAPON_BELINE,
	WEAPON_LASER,
	WEAPON_TRACK
};
class WeaponManager
{
public:
	WeaponManager(){}
	~WeaponManager(){}
	static WeaponManager* getInstance();
public:
	WeaponBasic * creatWeapon(int weap_kind);
};
#endif