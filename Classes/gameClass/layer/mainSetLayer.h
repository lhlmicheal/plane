#ifndef MENU_LAYER_H
#define MENU_LAYER_H
#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"

using namespace cocostudio;
using namespace ui;
using namespace std;
class MainSetLayer: public CCLayer
{
public:
	MainSetLayer(){};
	~MainSetLayer(){};
	virtual bool init();
	CREATE_FUNC(MainSetLayer);

	virtual void onEnter();
	virtual void onExit();

	void readUiData();
	void btnBackCall(Ref *pSender, TouchEventType type);
	void sliderChangeAudioCall(Ref *pSender,Slider::EventType type);
	void sliderChangeBMGCall(Ref *pSender,Slider::EventType type);
private:
	Button *back;
	Slider *slider_audio;
	Slider *slider_bmg;

};
#endif