#ifndef _RUNMAINLAYER_H
#define _RUNMAINLAYER_H
#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
using namespace ui;
class RunMainLayer:public Layer
{
public:
	CREATE_FUNC(RunMainLayer);
	virtual bool init();
	void onEnter();
	void onExit();
	void updataScore(int score);
	void updataMovTex(int dis);
private:
	void readUIData();
	void pauseCallBack(Ref *pSender,TouchEventType type);
	

	CCPoint size;
	CCSprite *hero_icon;
	CCSprite *score_icon;
	Label *hero_num;
	Label *score_text;
	Button *pause_btn;
	Label * Mov_text;
};
#endif