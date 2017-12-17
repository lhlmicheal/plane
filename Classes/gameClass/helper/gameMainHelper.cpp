#include "gameMainHelper.h"
#include "../plane/planeBase.h"
#include "../boom/boomBasic.h"
#include "../definedata/globalData.h"
#include "../manager/planeManager.h"
#include "../manager/bulletManager.h"
#include "../definedata/globalData.h"
#include "../manager/boomManager.h"

static GameMainHelper * _gamemainhelper = NULL;
GameMainHelper* GameMainHelper::getInstance()
{
	if(_gamemainhelper == NULL)
	{
		_gamemainhelper = new GameMainHelper();
	}
	return _gamemainhelper;
}

void GameMainHelper::attachLayer(RunPlayLayer *layer)
{
	playLayer = layer;
	playerBulletSheet = CCSpriteBatchNode::create("mainLayerUI/bullettp.png");
	playerBulletSheet->setPosition(ccp(0,0));
	playLayer->addChild(playerBulletSheet,20);

	heroPlane = playLayer->attchHeroPlane();
}
void GameMainHelper::initList()
{
	enemyList = CCArray::create();
	enemyList->retain();
	enemyBulletList = CCArray::create();
	enemyBulletList->retain();
	heroBulletList = CCArray::create();
	heroBulletList->retain();
	boomList = CCArray::create();
	boomList->retain();
}
void GameMainHelper::checkUpdata(float dt)
{
	if(isCanCheckEnemy)
	{
		checkEnemyList(dt);
		checkEnemyBulletList(dt);
		checkBoomList(dt);
	}
	checkPlayerBulletList(dt);
}
void GameMainHelper::checkBoomList(float dt)
{
	if(boomList->count()> 0)
	{
		for(int i = boomList->count()-1;i>=0;i--)
		{
			BoomBasic *boom =(BoomBasic *)boomList->objectAtIndex(i);
			if(!boom->isShow)
			{
				BoomManager::getInstance()->pushBoomPool(boom);
				boomList->removeObjectAtIndex(i);
			}
		}
	}
}
void GameMainHelper::checkPlayerBulletList(float dt)
{
	if(heroBulletList !=NULL)
	{
	int count = heroBulletList->count();
	for(int i =count -1;i >=0;i--)
	{
		BulletBase *bullet = (BulletBase*)heroBulletList->objectAtIndex(i);
		bullet->update(dt);
		if(GlobalData::sharedData()->isOutScreen(bullet))
		{
			bullet->setHide();
			removePlayerBullet(bullet);
		}else
		{
			for(int j = enemyList->count() -1;j>=0;j--)
			{
			PlaneBase* plane = (PlaneBase*)enemyList->objectAtIndex(j);
			if( (plane->type()>0) && bullet->boundingBox().intersectsRect(plane->boundingBox()))
			{
				if(GlobalData::sharedData()->isOutScreen(plane))
				{
					continue;
				}
				plane->reduceLife(bullet->power);
				bullet->connectEnemy();
			}
			}
		}
	}
	//¼ì²âÓëµÐÈËÅö×²
	}
}
void GameMainHelper::checkEnemyBulletList(float dt)
{
	if(enemyBulletList!=NULL)
	{
	int count = enemyBulletList->count();
	for(int i =count -1;i >=0;i--)
	{
		BulletBase *bullet =(BulletBase *)enemyBulletList->objectAtIndex(i);
		bullet->update(dt);
		if(GlobalData::sharedData()->isOutScreen(bullet))
		{
			bullet->setHide();
			removeEnemyBullet(bullet);
		}
			//¼ì²âÓëµÐÈËÅö×²
		if( bullet->boundingBox().intersectsRect(heroPlane->boundingBox()))
			{
				heroPlane->reduceLife(bullet->power);
				bullet->connectEnemy();
			}
	}
	}
}
void GameMainHelper::checkEnemyList(float dt)
{
	if(enemyList !=NULL)
	{
	int count = enemyList->count();
	if(count <=0)
	{
		return;
	}
	for(int i = enemyList->count()-1; i >=0;i--)
	{
		PlaneBase *plane = (PlaneBase *)enemyList->objectAtIndex(i);
		plane->update(dt);

		//¼ì²â·É»úÊÇ·ñ»¹Ã»ÓÐÏÔÊ¾£¬ÊÇ·ñËÀÍö£¬ÊÇ·ñ³öÆÁÄ»ÁË
		if((GlobalData::sharedData()->isOutScreen(plane)) )
		{
			plane->setHide();
			removeEnemy(plane);
			continue;
		}
		//·ñÔò¼ì²âÊÇ·ñÓëÖí½Å·É»úÅö×²
		//CCRect
		if(heroPlane->getBoundingBox().intersectsRect(plane->getBoundingBox()))
		{
			plane->destory();
		}
	}
	}
}
void GameMainHelper::initBoom(Point pos,int type)
{
	BoomBasic * boom =  BoomManager::getInstance()->createBoom(type,pos);
	boom->boomShow(pos);
	showBoom(boom);
}
void GameMainHelper::showBoom(BoomBasic* boom)
{
	boomList->addObject(boom);
}
float GameMainHelper::getMovDis()
{
	return dis_Mov;
}
void GameMainHelper::updataBgMov()
{
	dis_Mov+=1.5;
	if(mainLayer)
	mainLayer->updataMovTex(dis_Mov);
	auto it_show = LocalConfigData::sharedData()->planeShowConfig().begin();
	auto it_plane =LocalConfigData::sharedData()->planeConfig().begin();
	if(it_show !=LocalConfigData::sharedData()->planeShowConfig().end())
	{
		PlaneShowData data = *it_show;
		float type_hp = 0.0f;
		while(it_plane != LocalConfigData::sharedData()->planeConfig().end())
		{
			if(data.type == (*it_plane).type)
			{
				type_hp = (*it_plane).hp;
				break;
			}
			it_plane++;
		}
		if(dis_Mov >=data.showDis)
		{
			PlaneManager::getInstance()->showPlane(data,type_hp);
			if(!isCanCheckEnemy) isCanCheckEnemy =true;
			LocalConfigData::sharedData()->planeShowConfig().erase(it_show);
		}
	}
}
void GameMainHelper::removeEnemy(PlaneBase * enemyPlane)
{
	enemyList->removeObject(enemyPlane);
	PlaneManager::getInstance()->pushPlane(enemyPlane);
	playLayer->removeChild(enemyPlane);
}
void GameMainHelper::removePlayerBullet(BulletBase *bulletplayer)
{
	heroBulletList->removeObject(bulletplayer);
	BulletManager::getInstance()->pushPoolBullet(bulletplayer);
	
}
void GameMainHelper::removeEnemyBullet(BulletBase *bulletenemy)
{
	enemyBulletList ->removeObject(bulletenemy);
	BulletManager::getInstance()->pushPoolBullet(bulletenemy);
}
void GameMainHelper::showPlane(PlaneBase * enemyPlane)
{
	enemyList->addObject(enemyPlane);
	playLayer->addChild(enemyPlane);
}
void GameMainHelper::showBulletTest(BulletBase *bullet,Point firePostion,bool isHero)
{
	if(isHero)
	{
		heroBulletList->addObject(bullet);
	}
	else
	{
		enemyBulletList->addObject(bullet);
	}
	if(!bullet->isAddSheet)
	{
		playerBulletSheet->addChild(bullet,10);
		bullet->isAddSheet = true;
	}
}
void GameMainHelper::end()
{
	enemyList->release();
	enemyBulletList->release();
	heroBulletList->release();
	boomList->release();
	playerBulletSheet->removeFromParentAndCleanup(true);
	playerBulletSheet=NULL;
}
void GameMainHelper::gameEnd()
{
	if(playLayer)
	{
		playLayer->onExit();
	}
}
void GameMainHelper::changeScore(int score)
{
	GlobalData::sharedData()->setScore(GlobalData::sharedData()->getScore()+score);
	int Global_score = GlobalData::sharedData()->getScore();
	CCLog("GlobalData::sharedData.score=%d",Global_score);
	mainLayer->updataScore(Global_score);
}
void GameMainHelper::attachMainLayer(RunMainLayer *layer)
{
	mainLayer = layer;
}
Point GameMainHelper::getHeroGlobalPos()
{
	if(heroPlane && !heroPlane->isDead())
	{
		return heroPlane->getPosition();
	}
	return Point(-1,-1);
}