#include "mainSetLayer.h"
#include "../manager/audioManager.h"
#include "../manager/uilayermanager.h"
bool MainSetLayer::init()
{
	bool ret = true;
	if(!CCLayer::init())
	{
		ret =false;
	}
	readUiData();
	return ret;
}
void MainSetLayer::readUiData()
{
	ui::Widget * pNode=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("./mainLayerUI/menusetUI.json");	
	this->addChild(pNode);
	back = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"btn_back");
	slider_audio = (ui::Slider *)ui::Helper::seekWidgetByName(pNode,"slider_audio");
	slider_bmg = (ui::Slider *)ui::Helper::seekWidgetByName(pNode,"slider_bg");
}
void MainSetLayer::onEnter()
{
	CCLayer::onEnter();
	back->addTouchEventListener(this,toucheventselector(MainSetLayer::btnBackCall));
	slider_audio->addEventListener(CC_CALLBACK_2(MainSetLayer::sliderChangeAudioCall,this));
	float eff = AudioManager::getInstance()->getEffEctVolume();
	CCLog("eff== %f",eff);
	slider_audio->setPercent(100.0*eff);

	slider_bmg->addEventListener(CC_CALLBACK_2(MainSetLayer::sliderChangeBMGCall,this));
	float eff_bmg= AudioManager::getInstance()->getBackGroundMusicVolume();
	CCLog("eff== %f",eff_bmg);
	slider_bmg->setPercent(eff_bmg*100.0);
	
}
void MainSetLayer::onExit()
{
	CCLayer::onExit();

}
void MainSetLayer::btnBackCall(Ref *pSender, TouchEventType type)
{
	switch (type)    
    {    
        case TOUCH_EVENT_BEGAN:    
            CCLOG( "Began" );  
            break;               
        case TOUCH_EVENT_MOVED:    
            break;                  
        case TOUCH_EVENT_ENDED:  
			{
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON);
				UiLayerManager::getInstance()->removeLayer(this);
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;         
        default:    
            break;    
    }    
}
void MainSetLayer::sliderChangeAudioCall(Ref *pSender,Slider::EventType type)
{
	switch(type)
	{
	case Slider::EventType::ON_PERCENTAGE_CHANGED:
		{
			int percent = dynamic_cast<Slider*>(pSender)->getPercent();
			AudioManager::getInstance()->setEffectVolume(percent *0.01);
			CCLog("percent =%d",percent);
		}
		break;
	}
	
}
void MainSetLayer::sliderChangeBMGCall(Ref *pSender,Slider::EventType type)
{
	switch(type)
	{
	case Slider::EventType::ON_PERCENTAGE_CHANGED:
		{
			int percent = dynamic_cast<Slider*>(pSender)->getPercent();
			AudioManager::getInstance()->setBackGroundMusicVolume(percent *0.01);
			CCLog("percent =%d",percent);
		}
		break;
	}
	
}