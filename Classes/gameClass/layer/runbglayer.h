#ifndef _RUNBGLAYER_H
#define _RUNBGLAYER_H
#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
using namespace ui;

class RunBgLayer:public Layer
{
public:
	CREATE_FUNC(RunBgLayer);
	bool init();
	virtual void onEnter();
	virtual void onExit();
	void updateBg(float dt);
private:
	void pauseCallBack(Ref *pSender, TouchEventType type);
	void updataScore();

	Sprite *mbg01;
	Sprite *mbg02;
	Size mSize;
};
#endif