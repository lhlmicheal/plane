//#include "smallGreenPlane.h"
//#include "../helper/gameMainHelper.h"
//SmallGreenPlane * SmallGreenPlane::SmallGreenPlanecreate(const std::string & filename)
//{
//	SmallGreenPlane *plane = new SmallGreenPlane();
//	if(plane && plane->initWithFile(filename))
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;
//}
//
//SmallGreenPlane * SmallGreenPlane::SmallGreenPlanecreateWithSpriteFrame(SpriteFrame *spriteFrame)
//{
//	SmallGreenPlane *plane = new SmallGreenPlane();
//	if(plane&&spriteFrame && plane->initWithSpriteFrame(spriteFrame))
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;
//}
//SmallGreenPlane * SmallGreenPlane::SmallGreenPlanecreateWithPropetydata(PlaneProPtyData& prodata)
//{
//	SmallGreenPlane *plane = new SmallGreenPlane(prodata);
//	plane->initWithSpFrameName(prodata.texturename);
//	return plane;
//
//}
//bool SmallGreenPlane::initWithSpFrameName(const string spframename)
//{
//	PlaneBase::initWithSpFrameName(spframename);
//	return true;
//}
//bool  SmallGreenPlane::initWithPropetyData(PlaneProPtyData &data)
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
//	CCLog("SmallGreenPlane initWithPropetyData");
//	return true;
//}
//void SmallGreenPlane::initPosData(CCPoint pos,float hp)
//{
//	startPos = pos;
//	m_planelife = hp;
//	bulletCountTime =  1.0;
//	setVisible(true);
//	this->setPosition(ccp(startPos.x,startPos.y));
//}
//void SmallGreenPlane::movingToPoint(CCPoint *pos)
//{
//
//}
//void SmallGreenPlane::isDead()
//{
//
//}
//bool SmallGreenPlane::isShowing()
//{
//	
//	return m_planeisShowDis;
//}
//void SmallGreenPlane::updata(float dt)
//{
//	CCLog("SmallGreenPlane::updata");
//	checkPosition(dt);
//	if(isVisible())
//	{
//		checkWeapon(dt);
//	}
//	
//}
//void SmallGreenPlane::checkPosition(float dt)
//{
//	float offSetY = -1;
//	CCLog("SmallGreenPlanePosition.y=%f",getPositionY());
//	setPositionY (getPositionY()+offSetY);
//}
//void SmallGreenPlane::checkWeapon(float dt)
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