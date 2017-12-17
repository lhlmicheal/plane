#ifndef _bullet_base_H
#define _bullet_base_H
#include "cocos2d.h"
USING_NS_CC;
#include "../definedata/bulletpropertydata.h"
class BulletBase: public Sprite
{
public:
	BulletBase();
	BulletBase(const BulletProperty &data);

	///写这个接口因为工厂里村的都是bulletBase,又因为bullet都是要教导batchNode上,所以BulletBase
	///也要是sprite

	////写下面这个初始化是因为如果子弹类被继承由派生类创建后，调用初始化，也要把bulletBase初始化成ccsprite
	virtual bool initWithSpriteFrameName(const std::string &frameName);
	void resetShowBulletData(float datarotat,Point firepos);
	void resetPropetyData();
	virtual void update(float dt);
	virtual void checkPos(float dt);
	void connectEnemy();
	void setHide();
public:
	int rotate;
	Point startPos;
	float speed;
	float power;
	int type;
	bool isShow;
	/////子弹图片有宽高
	float imageWidth;
	float imageHeight;
	bool isAddSheet;//是否添加到图集;我们创建的每种类型的子弹只有固定数量，所以子弹是重复利用的。每一个子弹都被加到bulletSheet
								//所以不能被重复添加(node addchild()).
	Point targetPos;
	int direction;
private:
	BulletProperty mPropertyData;
};
#endif