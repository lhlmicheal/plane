#ifndef _Game_main_helper_H
#define _Game_main_helper_H
#include "cocos2d.h"
USING_NS_CC;
#include "../plane/heroPlane.h"
#include "../layer/runplaylayer.h"
#include "../layer/runmainlayer.h"
#include "../bullet/bulletBase.h"
#include "../boom/boomBasic.h"
class GameMainHelper
{
public:
	GameMainHelper(){
		heroPlane = nullptr;
		mainLayer = nullptr;
		dis_Mov = 0.0f;
		isCanCheckEnemy = false;
	}
	~GameMainHelper(){}
	static GameMainHelper* getInstance();
	void initList();
	void checkBoomList(float dt);
	void checkUpdata(float dt);
	void checkEnemyList(float dt);
	void checkPlayerBulletList(float dt);
	void checkEnemyBulletList(float dt);
	void initBoom(Point pos,int type);
	void showBoom(BoomBasic* boom);
	float getMovDis();

	void attachLayer(RunPlayLayer *layer);
	void attachMainLayer(RunMainLayer *layer);
	void removeEnemy(PlaneBase * enemyPlane);
	void removePlayerBullet(BulletBase *bulletplayer);
	void  removeEnemyBullet(BulletBase *bulletenemy);
	void end();
	void gameEnd();
	void showPlane(PlaneBase * enemyPlane);
	void showBulletTest(BulletBase *bullet,Point firePostion,bool isHero);

	void changeScore(int score);
	void updataBgMov();
	Point getHeroGlobalPos();

public:
		CCArray *enemyList;
		CCArray *enemyBulletList;
		CCArray *heroBulletList;
		CCArray *boomList;
		CCSpriteBatchNode *playerBulletSheet;
		HeroPlane *heroPlane;
		RunPlayLayer *playLayer;
		RunMainLayer *mainLayer;
private:
		float dis_Mov;
		bool isCanCheckEnemy;
};
#endif