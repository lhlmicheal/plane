#ifndef _PLANT_BASE_H
#define _PLANT_BASE_H
#include "cocos2d.h"
#include "../definedata/planepropertydata.h"
#include "../bullet/bulletBase.h"
USING_NS_CC;
class PlaneBase:public Sprite
{
public:
	PlaneBase(const PlaneProperty& data);
	PlaneBase();
	virtual bool initWithSpFrameName(const string spframename);

protected:
	int mType;
	int mLife;
	int mSpeed;

	bool mIsShow;
	Point mStartPos;
	int mScore;
	int mWeaponTag;
	int mWeaponLevel;

public:
	void resetShowData(const Point &pos, float hp);
	void resetProperty();
	void resetLife(int life);
	bool isDead();
    virtual bool isShowing();//还没有到显示的时候，先隐藏
	virtual void update(float dt);
	virtual void destory();
	int type();
	void setHide();
	virtual void reduceLife(int des);
private:
	PlaneProperty mPropertyData;
};
#endif