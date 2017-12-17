#ifndef _boomBasic_H
#define _boomBasic_H
#include "cocos2d.h"
USING_NS_CC;
#include <string>
using namespace std;
class BoomBasic:public CCSprite
{
public:
	BoomBasic();
	~BoomBasic();
	BoomBasic(int tag);

	virtual void boomShow(CCPoint pos);
	virtual void  initSpWithName(string filename);
	int getBoomTag();
	virtual void startPlayBoomAnima() = 0;
	virtual void finishPlayBoomAnima();
public:
	int boom_tag;
	bool isShow;
	bool isAdded;
	//CCArray *frames;
};
#endif