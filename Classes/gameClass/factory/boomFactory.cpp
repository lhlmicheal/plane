#include "boomFactory.h"
#include "../boom/boomTest.h"
BoomBasic * BoomFactory::CreateObjectFactory(int type)
{
	BoomBasic *boom = NULL;
	string boomName= "";
	switch (type)
	{
		case BoomType::BOOMTYPE_TEST:
		{
			boomName = "boom(1).png";
			boom = BoomTest::createBoomTestWithFileName(boomName,type);
		}
		break;
		case BoomType::BOOMTYPE_TEST2:
		{
		}
		break;
		case BoomType::BOOMTYPE_TEST3:
		{
		}
		break;
		default:
		break;
	}
	return boom;
}