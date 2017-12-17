#include "bulletFactory.h"
#include "../definedata/localconfigdata.h"
#include "../bullet/bulletdiffuse.h"
#include "../bullet/bulletbeline.h"
#include "../bullet/bulletsmallenemy.h"
BulletBase* BulletFactory::CreateObjectFactory(int type)
{
	BulletBase * bullet = NULL;
	BulletProperty bulletprodata;
	auto it = LocalConfigData::sharedData()->bulletConfig().begin();
	for(;it != LocalConfigData::sharedData()->bulletConfig().end();it++)
	{
			if((*it).type== type)
			{
			bulletprodata = *it;
			break;
			}
	}
	switch (type)
	{
	case BulletType::BULLET_PLAYER_DIFFUSE:
		{
			bullet = BulletDiffUse::createWithProptyData(bulletprodata);
		}
		break;
		case BulletType::BULLET_PLAYER_BELINE:
		{
			bullet = BulletBeLine::createWithProptyData(bulletprodata);
		}
		break;
		case BulletType::BULLET_SMALL_YELLOW:
		case BulletType::BULLET_SMALL_WHITE:
		case BulletType::BULLET_SMALL_RED:
		case BulletType::BULLET_SMALL_GREED:
		case BulletType::BULLET_SMALL_BLUE:
		{
			bullet = BulletSmallEnemy::createWithProptyData(bulletprodata);
		}
		break;
	default:
		break;
	}
	return bullet;
}