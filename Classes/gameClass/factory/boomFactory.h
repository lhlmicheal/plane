#ifndef _boomFactory_H
#define _boomFactory_H

#include "factoryBase.h"
#include "../boom/boomBasic.h"
enum BoomType
{
BOOMTYPE_TEST = 1,
BOOMTYPE_TEST2,
BOOMTYPE_TEST3
};
class BoomFactory:public FactoryBase<BoomBasic *>
{
public:
	BoomFactory(){};
	~BoomFactory(){};
	BoomBasic * CreateObjectFactory(int type);
};
#endif