#ifndef _PLAYERDEAD_H
#define _PLAYERDEAD_H
#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"
using namespace ui;

class PlayerDeadLayer:public Layer
{
public:
	CREATE_FUNC(PlayerDeadLayer);
	bool init();
	virtual void onEnter();
	virtual void onExit();
	void updateBg(float dt);
	void initListData();
private:
	void finishedCall(Ref *pSender, TouchEventType type);
	void autoRealiveCall(Ref *pSender, TouchEventType type);
	void updataScore();
	void readUiData();

	Button *mAutoRealiveBtn;
	Button *mFinishedBtn;
	ListView *mListView;
	ui::Widget * buyItem;
};
#endif