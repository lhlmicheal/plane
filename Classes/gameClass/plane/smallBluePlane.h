//#ifndef _Small_blue_plane_h
//#define _Small_blue_plane_h
//#include "planeBase.h"
//#include "../definedata/planeProptyData.h"
//#include "../weapon/weaponBasic.h"
//class SmallBluePlane:public PlaneBase
//{
//public:
//	SmallBluePlane(){}
//	SmallBluePlane(PlaneProPtyData &data):PlaneBase(data){
//	initWithPropetyData(data);
//	}
//	~SmallBluePlane(){}
//	virtual bool initWithSpFrameName(const string spframename);
//	static SmallBluePlane * SmallBluePlanecreate(const std::string & filename);
//	static SmallBluePlane * SmallBluePlanecreateWithSpriteFrame(SpriteFrame *spriteFrame);
//	static SmallBluePlane * SmallBluePlanecreateWithPropetydata(PlaneProPtyData& data);
//	bool  initWithPropetyData(PlaneProPtyData &data);
//public:
//	WeaponBasic * weaponArr[2];
//	virtual void movingToPoint(CCPoint *pos);
//	virtual void isDead();
//	bool isShowing();
//	virtual void updata(float dt);
//	virtual void initPosData(CCPoint pos,float hp);
//	void checkPosition(float dt);
//	void checkWeapon(float dt);
//public:
//	int disPlayPoint;
//	float bulletCountTime;
//};
//#endif