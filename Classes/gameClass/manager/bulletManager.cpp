#include "bulletManager.h"
#include "../helper/gameMainHelper.h"
#include "../definedata/globalData.h"
#include "../bullet/bulletsmallenemy.h"
#include "../bullet/bulletdiffuse.h"
#include "../bullet/bulletbeline.h"
BulletManager::BulletManager()
{

}
BulletManager::~BulletManager()
{

}
static BulletManager * _bulletmanager = nullptr;
BulletManager * BulletManager::getInstance()
{
	if(_bulletmanager == nullptr)
	{
		_bulletmanager = new BulletManager();
	}
	return _bulletmanager;
}
void BulletManager::initBulletPool()
{
	bulletFactory = new BulletFactory();
	bulletDiffUsePool = new GamePool<BulletBase*>(bulletFactory,50,BulletType::BULLET_PLAYER_DIFFUSE);
	bulletBelinePool = new GamePool<BulletBase*>(bulletFactory,60,BulletType::BULLET_PLAYER_BELINE);
	bulletSmallYellow = new GamePool<BulletBase*>(bulletFactory,20,BulletType::BULLET_SMALL_YELLOW);
	bulletSmallWhite = new GamePool<BulletBase*>(bulletFactory,20,BulletType::BULLET_SMALL_WHITE);
}
void BulletManager::createBullet(int bulletTag,Point firePosition,int rotate)
{
	createBulletFromPool(bulletTag,firePosition,rotate);
}
void BulletManager::createBullet(int bulletTag,Point firePosition,Point target)
{
	float dir_rotate = GlobalData::sharedData()->getRotateTwoPoint(firePosition, target);
	createBulletFromPool(bulletTag,firePosition,dir_rotate);

}
void BulletManager::createBulletFromPool(int bulletTag,Point firePostion,float rotate)
{
	BulletBase *bullet = NULL;
	bool isHero = false;
	switch (bulletTag)
	{
	case BulletType::BULLET_PLAYER_DIFFUSE:
		{
			bullet = (BulletDiffUse*)(bulletDiffUsePool->newObjectForTag());
			if(bullet !=NULL)
			{
				bullet->resetShowBulletData(rotate,firePostion);
			}
			isHero = true;
		break;
		}
		case BulletType::BULLET_PLAYER_BELINE:
		{
			bullet = (BulletBeLine*)(bulletBelinePool->newObjectForTag());
			if(bullet !=NULL)
			{
				bullet->resetShowBulletData(rotate,firePostion);
			}
			isHero = true;
		break;
		}
		case BulletType::BULLET_SMALL_YELLOW:
		{
			bullet = bulletSmallYellow->newObjectForTag();
			if(bullet !=NULL)
			{
			bullet->resetShowBulletData(rotate,firePostion);
			}
			isHero = false;
			break;
		}
		case BulletType::BULLET_SMALL_WHITE:
		{
			bullet = bulletSmallWhite->newObjectForTag();
			if(bullet !=NULL)
			{
			bullet->resetShowBulletData(rotate,firePostion);
			}
			isHero = false;
			break;
		}	
	default:
		break;
	}
	///判断池中子弹数量是否有剩余
	GameMainHelper::getInstance()->showBulletTest(bullet,firePostion,isHero);
}
void BulletManager::pushPoolBullet(BulletBase *bullet)
{
	int bulletTag = bullet->type;
	switch (bulletTag)
	{
	case BulletType::BULLET_PLAYER_DIFFUSE:
		{
			bulletDiffUsePool->freeOneObject(bullet);
		}
		break;
		case BulletType::BULLET_PLAYER_BELINE:
		{
			bulletBelinePool->freeOneObject(bullet);
		}
		break;
	case BulletType::BULLET_SMALL_YELLOW:
		{
			bulletSmallYellow->freeOneObject(bullet);
		}
		break;
		case BulletType::BULLET_SMALL_WHITE:
		{
			bulletSmallWhite->freeOneObject(bullet);
		}
		break;
	default:
		break;
	}
}