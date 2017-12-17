#include "runplaylayer.h"
#include "../manager/audioManager.h"
#include "../manager/uilayermanager.h"
#include "../manager/gamemanager.h"
#include "../definedata/globalData.h"
#include "../helper/gameMainHelper.h"
#include "../manager/bulletManager.h"
#include "../definedata/localconfigdata.h"
#include "../manager/planeManager.h"
#include "../manager/boomManager.h"
#include "../manager/animManager.h"
#include "playerdead.h"
RunPlayLayer::RunPlayLayer()
	: Layer()
	, mCanStart(false)
	, mStartTouchPos(Point::ZERO)
	, mEndTouchPos(Point::ZERO)
	, mHero(nullptr)
{
}
 bool RunPlayLayer::init()
 {
	bool ret = true;
	if(!Layer::init())
	{
		return ret = false;
	}
	EventDispatcher* eventdispatcher = CCDirector::sharedDirector()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(RunPlayLayer::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(RunPlayLayer::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(RunPlayLayer::onTouchEnded,this);
	listener->onTouchCancelled = CC_CALLBACK_2(RunPlayLayer::onTouchCancelled,this);
	eventdispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	initLayer();
	return ret;
 }
 void RunPlayLayer::initLayer()
 {
	 SpriteFrame *frame = SpriteFrameCache::sharedSpriteFrameCache()->getSpriteFrameByName("player3_01.png");
	 mHero = HeroPlane::heroPlanecreateWithSpriteFrame(frame);
	 mHero->setPosition(ccp(getContentSize().width/2,getContentSize().height/2));
	 addChild(mHero,2);
	 GameMainHelper::getInstance()->attachLayer(this);
	 PlaneManager::getInstance()->attachLayer(this);
 }
 void RunPlayLayer::onEnter()
 {
	 Layer::onEnter();
	 mCanStart = false;
	 SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/bullettp.plist","mainLayerUI/bullettp.png");
	 SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/gameBoom.plist", "mainLayerUI/gameBoom.png");
 	///读取配置飞机，武器数据
	LocalConfigData::sharedData();
	//初始化子弹池，飞机池, 爆炸
	GameMainHelper::getInstance()->initList();
	BulletManager::getInstance()->initBulletPool();
	PlaneManager::getInstance()->initPlanes();
    MyManagerAnimation::getInstance()->addAnimationWithFileAndName("gameBoom.plist", "boom");
	BoomManager::getInstance()->attachLayer(this);
	 mHero->initHeroData();
	 mCanStart = true;
	 schedule(schedule_selector(RunPlayLayer::update));
 }
 bool RunPlayLayer::onTouchBegan(Touch *touch, Event *unused_event)
 {
 //如果返回值是false，表示该层不处理该触摸事件，该层的touchMove，touchEnd也不会接收到该事件
//该消息传递给下级可以接受的事件处理层或者对象
//如果返回true，表示该层接受该触摸事件，并且会传递给该层的move和end。并且该层吞噬到该触摸事件
 //取得触摸点
	 mStartTouchPos = touch->getLocationInView();
    //将触摸点转换为GL坐标系的点
    mStartTouchPos = CCDirector::sharedDirector()->convertToGL(mStartTouchPos);
	return true;
 
 }
 void RunPlayLayer::onTouchMoved(Touch *touch, Event *unused_event)
 {
	 Point movPos = touch->getLocationInView();
	 movPos = CCDirector::sharedDirector()->convertToGL(movPos);

	 Point offset = movPos - mStartTouchPos;

	 mHero->setPosition(mHero->getPosition()+(offset));
	 //预判如果移除屏幕之外
	 Point hero_nextPos = mHero->getPosition();
		 if(hero_nextPos.x<(0+mHero->getContentSize().width/2)) 
		 {
			 mHero->setPositionX(0+mHero->getContentSize().width/2);
		 }
		 if(hero_nextPos.x>(GAME_WIDTH - mHero->getContentSize().width/2))
		 {
		 mHero->setPositionX(GAME_WIDTH - mHero->getContentSize().width/2);
		 }
		 if(hero_nextPos.y<(0+mHero->getContentSize().height/2))
		 {
		  mHero->setPositionY(0+mHero->getContentSize().height/2);
		 } 
		 if( hero_nextPos.y>(GAME_HIGHT - mHero->getContentSize().height/2))
		 {
			  mHero->setPositionY(GAME_HIGHT - mHero->getContentSize().height/2);
		 }
	 mStartTouchPos = movPos;
 }
 HeroPlane * RunPlayLayer::attchHeroPlane()
 {
	 return mHero;
 }
 void RunPlayLayer::onTouchEnded(Touch *touch, Event *unused_event)
 {
 }
 void RunPlayLayer::onTouchCancelled(Touch *touch, Event *unused_event)
 {
 }
void RunPlayLayer::onExit()
{
	unschedule(schedule_selector(RunPlayLayer::update));
	GameMainHelper::getInstance()->end();
	Layer::onExit();
}
void RunPlayLayer::update(float dt)
{
	bool over = mHero->isDead();
	if(mCanStart && !over) 
	{ 
		updateCheckPlayer(dt);
		GameMainHelper::getInstance()->checkUpdata(dt);
	}else if(over && HeroPlane::AutoLive <= 0)
	{
		//GameManager::getInstance()->setGameState(GAMESTATE::Pause);
		UiLayerManager::getInstance()->addPopLayer(PlayerDeadLayer::create());
	}
}
void RunPlayLayer::updateCheckPlayer(float dt)
{
	mHero->update(dt);
}