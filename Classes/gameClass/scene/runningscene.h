#ifndef _RUNNING_SCENE_H
#define _RUNNING_SCENE_H
#include "cocos2d.h"
USING_NS_CC;
#include "../layer/runplaylayer.h"
class RunningScene : public Scene
{
public:
	RunningScene();
	static RunningScene *create();

private:
	Layer *mRootlayer;
};
#endif