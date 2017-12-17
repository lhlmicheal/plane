#ifndef _GLOBALDATA_H
#define _GLOBALDATA_H
using namespace std;
#include <string>
#include "cocos2d.h"
#include "../plane/planeBase.h"
#include "../bullet/bulletBase.h"
USING_NS_CC;
#define GAME_HIGHT 800
#define GAME_WIDTH 480
#define SHAPER_PI 3.14159265 
#define DEVIATION 0.00001
class GlobalData
{
public:
	static GlobalData* sharedData();
	void initData();
	void setScore(int score);
	int getScore();
	void updataScore();
	////////global mathod
	bool isOutScreen(PlaneBase *obj);
	bool isOutScreen(BulletBase *obj);
	std::vector<string> splitStringWithLimit(string str,string limit);
	float getRotateTwoPoint(Point sef,Point Tar);
public:
	//int gold;
	static float arrsin[90];
	static float arrcos[90];
	int m_score;
};
#endif