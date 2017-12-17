#include "mainMenulayer.h"
#include "../manager/audioManager.h"
#include "../manager/UiLayerManager.h"
#include "../layer/mainSetLayer.h"
#include "../scene/runningscene.h"
bool MainMenuLayer::init()
{
	bool ret = true;
	if(!Layer::init()) return false;
	readUiData();
	return  ret;	
}
void MainMenuLayer::readUiData()
{
	ui::Widget * pNode=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("./mainlayerUI/UIgamemenulayer.json");	
	this->addChild(pNode);
	startBtn = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"btn_start");
	quitBtn = (Button *)Helper::seekWidgetByName(pNode,"btn_quit");
	setBtn = (Button *)Helper::seekWidgetByName(pNode,"btn_set");
	playerImager = (CCSprite *)Helper::seekWidgetByName(pNode,"Image_5");
	//playerImager->setRotation(-30);
}
void MainMenuLayer::onEnter()
{
	Layer::onEnter();
	AudioManager::getInstance()->playBackGroundMusic(MUSIC_BG_SENCE_UI, true);
	startBtn->addTouchEventListener( this, toucheventselector(MainMenuLayer::btnStartCall));
	setBtn->addTouchEventListener(this,toucheventselector(MainMenuLayer::btnSetCall));
	quitBtn->addTouchEventListener(this,toucheventselector(MainMenuLayer::btnQuitCall));
}
void MainMenuLayer::onExit()
{
	Layer::onExit();
}
void MainMenuLayer::btnStartCall(Ref *pSender, TouchEventType type)
{
	switch (type)    
    {                
        case TOUCH_EVENT_ENDED:  
			{
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON);
				AudioManager::getInstance()->stopBackGroundMusic(true);
				UiLayerManager::getInstance()->removeAllLayer();
				CCDirector::getInstance()->replaceScene(RunningScene::create());
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;         
        default:    
            break;    
    }    
}
void MainMenuLayer::btnSetCall(Ref*pSender,TouchEventType type)
{
switch (type)    
    {                    
        case TOUCH_EVENT_ENDED:  
			{
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON);
				UiLayerManager::getInstance()->addPopLayer(MainSetLayer::create());
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;        
        default:    
            break;    
    }  
}
void MainMenuLayer::btnQuitCall(Ref*pSender,TouchEventType type)
{
switch (type)    
    {     
        case TOUCH_EVENT_ENDED:  
			{
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON,false);
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;    
        default:    
            break;    
    }  
}