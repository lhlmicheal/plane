#include "planeFactory.h"
#include "../plane/enemysmallplane.h"
#include "../definedata/LocalConfigData.h"
#include "../definedata/planepropertydata.h"
PlaneBase * PlaneFactory::CreateObjectFactory(int type)
 {
	 PlaneBase * plane = NULL;
	 PlaneProperty planeProdata;
	 auto it = LocalConfigData::sharedData()->planeConfig().begin();
	 for(;it !=LocalConfigData::sharedData()->planeConfig().end();it++)
	 {
		 if((*it).type  == type)
		{
			planeProdata = *it;
			break;
		}
	 }
	 switch(type)
	 {
		case planeType::ENEMY_YELLOW:
		case planeType::ENEMY_WHITE:
		case planeType::ENEMY_RED:
		case planeType::ENEMY_GREEN:
		case planeType::ENEMY_BLUE:
		 {
			 plane = EnemySmallPlane::createWithPropetydata(planeProdata);
		 }
		 break;
	 default:
		 break;
	 }
	 return plane;
}