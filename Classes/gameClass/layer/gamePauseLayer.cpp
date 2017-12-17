#include "gamePauseLayer.h"
#include "../manager/audioManager.h"
#include "../manager/uilayermanager.h"
#include "../manager/gameManager.h"
 bool GamePauseLayer::init()
 {
	 bool ret = true;
	 if(!CCLayer::init())
	 {
		 ret = false;
		 return ret;
	 }
	 readUIData();
	 return ret;
 }
 void GamePauseLayer::readUIData()
 {
	 ui::Widget * pNode=cocostudio::GUIReader::getInstance()->widgetFromJsonFile("./mainLayerUI/gamePauseUI.json");	
	this->addChild(pNode);
	resume_btn = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"back_btn");
	resume_btn->addTouchEventListener(this,toucheventselector(GamePauseLayer::backCallBack));
	
	/*menu_btn = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"menu_btn");
	menu_btn->addTouchEventListener(this,toucheventselector(GamePauseLayer::menuCallBack));
	*/
	quit_btn = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"quit_btn");
	quit_btn->addTouchEventListener(this,toucheventselector(GamePauseLayer::quitCallBack));
	
	share_btn = (ui::Button *)ui::Helper::seekWidgetByName(pNode,"share_btn");
	share_btn->addTouchEventListener(this,toucheventselector(GamePauseLayer::shareCallBack));
 }
 void GamePauseLayer::backCallBack(Ref *pSender, TouchEventType type)
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
  void GamePauseLayer::menuCallBack(Ref *pSender, TouchEventType type)
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
				AudioManager::getInstance()->playEffect(EFFECT_BUTTON,false);
				GameManager::getInstance()->setGameState(GAMESTATE::MainMenu);
				
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;         
        default:    
            break;  
	 }

 }
   void GamePauseLayer::quitCallBack(Ref *pSender, TouchEventType type)
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
				GameManager::getInstance()->setGameState(GAMESTATE::Quit);
			}
            break;    
        case TOUCH_EVENT_CANCELED:    
            break;         
        default:    
            break;  
	 }

 }
    void GamePauseLayer::shareCallBack(Ref *pSender, TouchEventType type)
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
 void GamePauseLayer::onEnter()
 {
	 CCLayer::onEnter();
 
 }
void GamePauseLayer::onExit()
{
	CCLayer::onExit();
}