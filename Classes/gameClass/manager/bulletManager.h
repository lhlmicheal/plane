#ifndef _bulletManager_h
#define _bulletManager_h
#include "../pool/gamePool.h"
#include "../bullet/bulletBase.h"
#include "../factory/bulletFactory.h"
#include "../layer/runplaylayer.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	static BulletManager * getInstance();
public:
	BulletFactory *bulletFactory;
	////±ê×¼×Óµ¯³Ø
	GamePool<BulletBase *>* bulletDiffUsePool;
	GamePool<BulletBase *>* bulletBelinePool;
	GamePool<BulletBase *>* bulletSmallYellow;
	GamePool<BulletBase *>* bulletSmallWhite;
	RunPlayLayer *mainlayer;
	void initBulletPool();
	void createBullet(int bulletTag,Point firePosition,int rotate);
	void createBullet(int bulletTag,Point firePosition,Point target);
	void createBulletFromPool(int bulletTag,Point firePostion,float rotate);
	void pushPoolBullet(BulletBase *bullet);
};
#endif