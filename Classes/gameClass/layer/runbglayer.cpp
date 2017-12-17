#include "runbglayer.h"
#include "../manager/audioManager.h"
#include "../manager/uilayermanager.h"
#include "../helper/gameMainHelper.h"
bool RunBgLayer::init()
 {
	bool ret = true;
	if(!Layer::init())
	{
		return ret = false;
	}
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/gameBoom.plist", "mainLayerUI/gameBoom.png");
	mSize = CCDirector::getInstance()->getVisibleSize();
	setContentSize(mSize);

	mbg01 = Sprite::create("gamebg/bg02.jpg");
	mbg01->setAnchorPoint(ccp(0,0));
	mbg01->setPosition(ccp(0,0));
	addChild(mbg01,1);
	mbg02 = Sprite::create("gamebg/bg02.jpg");
	mbg02->setAnchorPoint(ccp(0,0));
	mbg02->setPosition(ccp(0,mbg01->getContentSize().height));
	addChild(mbg02,1);
	return ret;
 }
 void RunBgLayer::pauseCallBack(Ref *pSender, TouchEventType type)
 {
	 switch (type)
	 {   
        case TOUCH_EVENT_ENDED:  
			{
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON,false);
				UiLayerManager::getInstance()->removeLayer(this);
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;         
        default:    
            break;  
	 }
 }
 void RunBgLayer::onEnter()
 {
	 Layer::onEnter();
	 AudioManager::getInstance()->playBackGroundMusic(MUSIC_BG_SENCE_FIHT);
	 schedule(schedule_selector(RunBgLayer::updateBg));
 }
void RunBgLayer::onExit()
{
	Layer::onExit();
}
void RunBgLayer::updateBg(float dt)
{
	if(mbg01->getPositionY() < (-mSize.height ))
	{
		mbg01->setPositionY(mbg02->getPositionY()+mbg02->getContentSize().height);
	}else if(mbg02->getPositionY() < (-mSize.height))
	{
		mbg02->setPositionY(mbg01->getPositionY()+mbg01->getContentSize().height);
	}
	else
	{
	mbg01->setPositionY(mbg01->getPositionY()-1.0f);
	mbg02->setPositionY(mbg02->getPositionY()-1.0f);
	}
	GameMainHelper::getInstance()->updataBgMov();
}