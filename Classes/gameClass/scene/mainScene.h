#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_
#include "cocos2d.h"
#include "../layer/mainMenulayer.h"
USING_NS_CC;
using namespace std;
class GameMainScene:public Scene
{
public:
	static GameMainScene *create();
	enum LAYER_LEVEL
	{
	    BGLAYER = 0,
	    ADORNMENTLAYER,
	    SHADOWLAYER,
	    UILAYER,
	    POPLAYER,
	    EFFECTLAYER
	};
private:
};
#endif