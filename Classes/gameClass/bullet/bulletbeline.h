#ifndef BULLET_BELINE
#define BULLET_BELINE
#include <string>
using namespace std;
#include "bulletBase.h"
#include "../definedata/bulletpropertydata.h"
class BulletBeLine:public BulletBase
{
public:
	BulletBeLine(const BulletProperty &data);
	static BulletBeLine * createWithProptyData(const BulletProperty &data);
	virtual bool initWithSpriteFrameName(const std::string &framename);
public:
	void update(float dt);
	void checkPos(float dt);
};
#endif