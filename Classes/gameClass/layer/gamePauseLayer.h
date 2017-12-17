#ifndef _GamePauseLAYER_H
#define _GamePauseLAYER_H
#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
using namespace ui;

class GamePauseLayer:public CCLayer
{
public:
	GamePauseLayer(){};
	~GamePauseLayer(){};
	CREATE_FUNC(GamePauseLayer);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
private:
	void readUIData();
	void backCallBack(Ref *pSender, TouchEventType type);
	void menuCallBack(Ref *pSender, TouchEventType type);
	void quitCallBack(Ref *pSender, TouchEventType type);
	void shareCallBack(Ref *pSender, TouchEventType type);
	void updataScore();

    Button *resume_btn;
	Button *menu_btn;
	Button *quit_btn;
	Button *share_btn;


};
#endif