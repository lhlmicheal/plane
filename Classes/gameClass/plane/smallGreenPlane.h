//#ifndef _small_green_plane_h
//#define _small_green_plane_h
//#include "planeBase.h"
//#include "../definedata/planeProptyData.h"
//#include "../weapon/weaponBasic.h"
//class SmallGreenPlane:public PlaneBase
//{
//public:
//	SmallGreenPlane(){}
//	SmallGreenPlane(PlaneProPtyData &data):PlaneBase(data){
//	initWithPropetyData(data);
//	}
//	~SmallGreenPlane(){}
//	virtual bool initWithSpFrameName(const string spframename);
//	static SmallGreenPlane * SmallGreenPlanecreate(const std::string & filename);
//	static SmallGreenPlane * SmallGreenPlanecreateWithSpriteFrame(SpriteFrame *spriteFrame);
//	static SmallGreenPlane * SmallGreenPlanecreateWithPropetydata(PlaneProPtyData& data);
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