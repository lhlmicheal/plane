#ifndef BULLET_DIFF_USE
#define BULLET_DIFF_USE
#include <string>
using namespace std;
#include "bulletBase.h"
#include "../definedata/bulletpropertydata.h"
class BulletDiffUse:public BulletBase
{
public:
	BulletDiffUse(const BulletProperty &data);
	static BulletDiffUse * createWithProptyData(const BulletProperty &data);
	virtual bool initWithSpriteFrameName(const std::string &framename);
public:
	void update(float dt);
	void checkPos(float dt);
};
#endif