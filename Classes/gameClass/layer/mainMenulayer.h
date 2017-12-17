#ifndef _MAINMMENULAYER_H
#define _MAINMMENULAYER_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;
USING_NS_CC;
using namespace ui;
using namespace std;
class MainMenuLayer: public Layer
{
public:
	 bool init();
	CREATE_FUNC(MainMenuLayer);
	virtual void onEnter();
	virtual void onExit();

	//ui::Button
	Button *quitBtn;
	Button *startBtn;
	Button *setBtn;
	Sprite *playerImager;

	void readUiData();
	void btnStartCall(Ref *pSender, TouchEventType type);
	void btnSetCall(Ref*pSender,TouchEventType type);
	void btnQuitCall(Ref*pSender,TouchEventType type);

private:

};
#endif