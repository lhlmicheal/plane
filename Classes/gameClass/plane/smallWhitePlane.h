//#ifndef _small_white_plane_h
//#define _small_white_plane_h
//#include "planeBase.h"
//#include "../definedata/planeProptyData.h"
//#include "../weapon/weaponBasic.h"
//class SmallWhitePlane:public PlaneBase
//{
//public:
//	SmallWhitePlane(){}
//	SmallWhitePlane(PlaneProPtyData &data):PlaneBase(data){
//	initWithPropetyData(data);
//	}
//	~SmallWhitePlane(){}
//	virtual bool initWithSpFrameName(const string spframename);
//	static SmallWhitePlane * SmallWhitePlanecreate(const std::string & filename);
//	static SmallWhitePlane * SmallWhitePlanecreateWithSpriteFrame(SpriteFrame *spriteFrame);
//	static SmallWhitePlane * SmallWhitePlanecreateWithPropetydata(PlaneProPtyData& data);
//	bool  initWithPropetyData(PlaneProPtyData &data);
//public:
//		WeaponBasic * weaponArr[2];
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