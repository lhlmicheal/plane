#include "runmainlayer.h"
#include "../manager/audioManager.h"
#include "../manager/uilayermanager.h"
#include "../manager/gameManager.h"
#include "gamePauseLayer.h"
#include "../definedata/globalData.h"
 bool RunMainLayer::init()
 {
	 bool ret = true;
	 if(!Layer::init())
	 {
		 ret = false;
		 return ret;
	 }
	size = CCDirector::getInstance()->getWinSize();
	 readUIData();
	 return ret;
 }
 void RunMainLayer::readUIData()
 {
	 hero_icon = CCSprite::createWithSpriteFrameName("character_01.png");
	 hero_icon->setPosition(ccp(0+hero_icon->getContentSize().width/2,size.y-hero_icon->getContentSize().height/2));
	 this->addChild(hero_icon);
	 
	 hero_num = Label::createWithTTF("123456", "fonts/FZDHTK.TTF", 30.0f);
	 hero_num ->setAnchorPoint(ccp(0,0.5));
	 hero_num ->setPosition(ccp(hero_icon->getContentSize().width,hero_icon->getContentSize().height/2));
	 hero_icon->addChild(hero_num);

	 score_icon = CCSprite::createWithSpriteFrameName("rete_01.png");
	 score_icon->setPosition(ccp(getContentSize().width/2+score_icon->getContentSize().width/2,size.y-score_icon->getContentSize().height/2));
	 this->addChild(score_icon);


	score_text = Label::createWithTTF("123456", "fonts/FZDHTK.TTF", 30.0f);
	 score_text ->setAnchorPoint(ccp(0,0.5));
	 score_text->setString("0");
	 score_text ->setPosition(ccp(score_icon->getContentSize().width,score_icon->getContentSize().height/2));
	 score_icon->addChild(score_text);

	 pause_btn = Button::create("back_1.png","back_2.png","back_2.png",TextureResType::PLIST);
	 pause_btn->setPosition(ccp(size.x-pause_btn->getContentSize().width/2,size.y-pause_btn->getContentSize().height/2));
	 this->addChild(pause_btn,1);
	 pause_btn->addTouchEventListener(this,toucheventselector(RunMainLayer::pauseCallBack));

	 Mov_text = Label::createWithTTF("Mov_::0", "fonts/FZDHTK.TTF", 30.0f);
	 Mov_text ->setAnchorPoint(ccp(1,0.5));
	 Mov_text->setString("Mov_::0");
	 Mov_text ->setPosition(ccp(size.x-2,30));
	 this->addChild(Mov_text);
 }
 void RunMainLayer::onEnter()
 {
	 Layer::onEnter();
	 setTouchEnabled(true);
 
 }
void RunMainLayer::onExit()
{
	Layer::onExit();
}
void RunMainLayer::pauseCallBack(Ref *pSender,TouchEventType type)
{
	switch (type)
	{
		case TouchEventType::TOUCH_EVENT_ENDED:
		{
			AudioManager::getInstance()->playEffect(EFFECT_BUTTON,false);
			GameManager::getInstance()->setGameState(GAMESTATE::Pause);
			UiLayerManager::getInstance()->addPopLayer(GamePauseLayer::create());
		}
		break;
		case TouchEventType::TOUCH_EVENT_CANCELED:
		{
		
		}
		break;
	default:
		break;
	}
}
void RunMainLayer::updataScore(int score)
{
	int text_core = atoi(score_text->getString().c_str());
	int upcore = GlobalData::sharedData()->getScore() -text_core;
	string tempstr ="";
	CCLog("upCore=%d",upcore);
	if(upcore >20)
	{
		tempstr = CCString::createWithFormat("%d",text_core+8)->getCString();
		score_text->setString(tempstr);
		updataScore(upcore);
	}else if(upcore >10 && upcore <=20)
	{
		tempstr = CCString::createWithFormat("%d",text_core+5)->getCString();
		score_text->setString(tempstr);
		updataScore(upcore);
	}
	else if(upcore >5 && upcore <=10)
	{
		tempstr = CCString::createWithFormat("%d",text_core+2)->getCString();
		score_text->setString(tempstr);
		updataScore(upcore);
	}else if(upcore >=1 && upcore <=5)
	{
		tempstr = CCString::createWithFormat("%d",text_core+1)->getCString();
		score_text->setString(tempstr);
		updataScore(upcore);
	}else
	{
		return;
	}
}
void RunMainLayer::updataMovTex(int dis)
{
	CCString *str = CCString::createWithFormat("Mov_::%d",dis);
	Mov_text->setString(str->getCString());
}