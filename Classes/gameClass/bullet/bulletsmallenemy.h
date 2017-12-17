#ifndef _bullet_Ene_Small1_H
#define _bullet_Ene_Small1_H
#include <string>
using namespace std;
#include "bulletBase.h"
#include "../definedata/bulletpropertydata.h"
class BulletSmallEnemy:public BulletBase
{
public:
	BulletSmallEnemy(const BulletProperty &data);
	static BulletSmallEnemy * createWithProptyData(const BulletProperty &data);
	virtual bool initWithSpriteFrameName(const std::string &framename);
public:
	 void update(float dt);
	 void checkPos(float dt);
};
#endif