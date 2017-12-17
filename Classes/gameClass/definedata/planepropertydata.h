#ifndef _PLANEPROPERTY_H
#define _PLANEPROPERTY_H
#include <string>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class PlaneProperty
{
public:
	string texturename;
	int type;
	int hp;
	int speed;
	int score;
	int weaponTag;
	
	 PlaneProperty()
	 {
		texturename ="";
		type = -1;
		hp = 0;
		speed = 0;
		score = 0;
		weaponTag = -1;
	}
};
class PlaneShowData
{
public:
	int type;
	int showDis;
	Point configPos;
	
	PlaneShowData()
	{
		type = -1;
		showDis = -1;
		configPos = Point::ZERO;
	}
};
#endif