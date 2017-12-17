#ifndef _RUNPLAYLAYER_H
#define _RUNPLAYLAYER_H
#include "cocos2d.h"
USING_NS_CC;
#include "../plane/heroPlane.h"
class RunPlayLayer:public Layer
{
public:
	RunPlayLayer();
	CREATE_FUNC(RunPlayLayer);
	bool init();
	virtual void onEnter();
	virtual void onExit();

	bool onTouchBegan(Touch *touch, Event *unused_event); 
    void onTouchMoved(Touch *touch, Event *unused_event); 
    void onTouchEnded(Touch *touch, Event *unused_event); 
    void onTouchCancelled(Touch *touch, Event *unused_event);
public:
	HeroPlane *attchHeroPlane();
private:
	void initLayer();
	void updateScore();
	void update(float dt);
	void updateCheckPlayer(float dt);
	
	bool mCanStart;
	Point mStartTouchPos;
	Point mEndTouchPos;
	HeroPlane *mHero;
};
#endif