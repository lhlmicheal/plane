//#include "smallBluePlane.h"
//#include "../helper/gameMainHelper.h"
//SmallBluePlane * SmallBluePlane::SmallBluePlanecreate(const std::string & filename)
//{
//	SmallBluePlane *plane = new SmallBluePlane();
//	if(plane && plane->initWithFile(filename))
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;
//}
//
//SmallBluePlane * SmallBluePlane::SmallBluePlanecreateWithSpriteFrame(SpriteFrame *spriteFrame)
//{
//	SmallBluePlane *plane = new SmallBluePlane();
//	if(plane&&spriteFrame && plane->initWithSpriteFrame(spriteFrame))
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;
//}
//SmallBluePlane * SmallBluePlane::SmallBluePlanecreateWithPropetydata(PlaneProPtyData& prodata)
//{
//	SmallBluePlane *plane = new SmallBluePlane(prodata);
//	plane->initWithSpFrameName(prodata.texturename);
//		return plane;
//
//}
//bool SmallBluePlane::initWithSpFrameName(const string spframename)
//{
//	PlaneBase::initWithSpFrameName(spframename);
//	return true;
//}
//bool  SmallBluePlane::initWithPropetyData(PlaneProPtyData &data)
//{
//	disPlayPoint = data.disPlaydis;
//	m_weaponTag = data.weaponTag;
//	weaponArr[0] =NULL;
//	weaponArr[1] =NULL;
//	if(weaponArr[0] == NULL)
//	{
//		weaponArr[0] = WeaponManager::getInstance()->creatWeapon(m_weaponTag);
//		weaponArr[0]->equipweapon(this);
//	}
//	CCLog("SmallBluePlane initWithPropetyData");
//	return true;
//}
//void SmallBluePlane::initPosData(CCPoint pos,float hp)
//{
//	startPos = pos;
//	m_planelife = hp;
//	bulletCountTime =  1.0;
//	setVisible(true);
//	this->setPosition(ccp(startPos.x,startPos.y));
//}
//void SmallBluePlane::movingToPoint(CCPoint *pos)
//{
//
//}
//void SmallBluePlane::isDead()
//{
//
//}
//bool SmallBluePlane::isShowing()
//{
//	
//	return m_planeisShowDis;
//}
//void SmallBluePlane::updata(float dt)
//{
//	CCLog("SmallBluePlane::updata");
//	checkPosition(dt);
//	if(isVisible())
//	{
//		checkWeapon(dt);
//	}
//	
//}
//void SmallBluePlane::checkPosition(float dt)
//{
//	float offSetY = -1;
//	CCLog("SmallBluePlanePosition.y=%f",getPositionY());
//	setPositionY (getPositionY()+offSetY);
//}
//void SmallBluePlane::checkWeapon(float dt)
//{
//	bulletCountTime -=dt;
//	if(bulletCountTime < 0)
//	{
//		bulletCountTime =2.0f;
//		if(weaponArr[0] != NULL)
//		{
//			weaponArr[0]->setFirePos(getPosition());
//			weaponArr[0]->updata(dt);
//		}
//	
//	}
//}
//
