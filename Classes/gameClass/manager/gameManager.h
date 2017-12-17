#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include "cocos2d.h"
USING_NS_CC;
using namespace std;
enum GAMESTATE
{
	MainMenu,
	Running,
	Pause,
	Quit
};
class GameManager : public CCObject
{
public:
	GameManager();
	~GameManager();
	static GameManager* getInstance();
	void setGameState(int state);
	int getGameState();
private:
	int gameState;
};
#endif