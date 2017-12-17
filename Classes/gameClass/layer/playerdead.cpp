#include "playerdead.h"
#include "../manager/audioManager.h"
#include "../manager/uilayermanager.h"
#include "../helper/gameMainHelper.h"
#include "../manager/gameManager.h"
bool PlayerDeadLayer::init()
 {
	bool ret = true;
	if(!Layer::init())
	{
		return ret = false;
	}
	readUiData();
	return ret;
 }
 void PlayerDeadLayer::finishedCall(Ref *pSender, TouchEventType type)
 {
	 switch (type)
	 {   
        case TOUCH_EVENT_ENDED:  
			{
				GameManager::getInstance()->setGameState(GAMESTATE::MainMenu);
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON,false);
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;         
        default:    
            break;  
	 }
 }
 void PlayerDeadLayer::autoRealiveCall(Ref *pSender, TouchEventType type)
 {
	 switch (type)
	 {   
        case TOUCH_EVENT_ENDED:  
			{
				GameManager::getInstance()->setGameState(GAMESTATE::Running);
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
 void PlayerDeadLayer::onEnter()
 {
	 Layer::onEnter();
	 mFinishedBtn->addTouchEventListener( this, toucheventselector(PlayerDeadLayer::finishedCall));
	 mListView->setTouchEnabled(true);
	 initListData();

 }
void PlayerDeadLayer::onExit()
{
	Layer::onExit();
}
void PlayerDeadLayer::readUiData()
{
	ui::Widget * pNode=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("./mainLayerUI/gameDeadUI.json");	
	this->addChild(pNode);
	buyItem = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("./mainLayerUI/gameBuyItemUI.json");
	mFinishedBtn = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"finished_btn");
	mListView = (ui::ListView *)ui::Helper::seekWidgetByName(pNode,"buy_list");

}
void PlayerDeadLayer::initListData()
{
	mListView->setItemModel(buyItem);
	for(int i = 0; i< 5; i++)
	{
		mListView->pushBackDefaultItem();
	}
	
}