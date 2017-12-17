#include "gameManager.h"
#include "../scene/mainScene.h"
#include "../helper/gameMainHelper.h"
#include "../manager/audioManager.h"
#include "uilayermanager.h"
static GameManager* _gamemanager = NULL;

GameManager * GameManager::getInstance()
{
	if( _gamemanager == NULL)
	{
		_gamemanager = new GameManager();
	}
	return _gamemanager;
}
GameManager::GameManager()
{
	gameState = 0;
}
GameManager::~GameManager()
{
	if(_gamemanager != NULL)
	{
		delete _gamemanager;
		_gamemanager = NULL;
	}
}
void GameManager::setGameState(int state)
{
	//gameState = state;
	if(gameState == state)
	{
		return ;
	}
	gameState = state;
	switch (gameState)
	{
	case GAMESTATE::MainMenu:
		{
			if(CCDirector::sharedDirector()->isPaused())
			CCDirector::sharedDirector()->resume();

			UiLayerManager::getInstance()->removeAllLayer();
			CCDirector::sharedDirector()->replaceScene(GameMainScene::create());
		}
		break;
	case GAMESTATE::Pause:
		{
			AudioManager::getInstance()->playEffect(EFFECT_BUTTON,false);
			CCDirector::sharedDirector()->pause();
			AudioManager::getInstance()->pauseBackGroundMusic();
		}
		break;
	case GAMESTATE::Running:
		{
			CCDirector::sharedDirector()->resume();
			AudioManager::getInstance()->resumeBackGroundMusic();
		}
		break;
	case GAMESTATE::Quit:
		{
			CCDirector::sharedDirector()->end();
		}
		break;
	default:
		break;
	}
}
int GameManager::getGameState()
{
	return gameState;
}
