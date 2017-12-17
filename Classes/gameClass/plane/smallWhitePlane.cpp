//#include "smallWhitePlane.h"
//#include "../helper/gameMainHelper.h"
//SmallWhitePlane * SmallWhitePlane::SmallWhitePlanecreate(const std::string & filename)
//{
//	SmallWhitePlane *plane = new SmallWhitePlane();
//	if(plane && plane->initWithFile(filename))
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;
//}
//
//SmallWhitePlane * SmallWhitePlane::SmallWhitePlanecreateWithSpriteFrame(SpriteFrame *spriteFrame)
//{
//	SmallWhitePlane *plane = new SmallWhitePlane();
//	if(plane&&spriteFrame && plane->initWithSpriteFrame(spriteFrame))
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;
//}
//SmallWhitePlane * SmallWhitePlane::SmallWhitePlanecreateWithPropetydata(PlaneProPtyData& prodata)
//{
//	/*SmallWhitePlane *plane = new SmallWhitePlane(prodata);
//	SpriteFrame *frame = CCSpriteFrameCache::getInstance()->getSpriteFrameByName(prodata.texturename);
//	if(plane&&frame&&plane->initWithSpriteFrame(frame)&&plane->initData())
//	{
//		plane->autorelease();
//		return plane;
//	}
//	CC_SAFE_DELETE(plane);
//	return nullptr;*/
//	SmallWhitePlane *plane = new SmallWhitePlane(prodata);
//	plane->initWithSpFrameName(prodata.texturename);
//	return plane;
//
//}
//bool SmallWhitePlane::initWithSpFrameName(const string spframename)
// {
//	 PlaneBase::initWithSpFrameName(spframename);
//	return true;
// }
//bool  SmallWhitePlane::initWithPropetyData(PlaneProPtyData &data)
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
//	CCLog("SmallWhitePlane initWithPropetyData");
//	return true;
//}
//void SmallWhitePlane::initPosData(CCPoint ps,float hp)
//{
//	startPos = ps;
//	m_planelife = hp;
//	bulletCountTime = 0.1;
//	setVisible(true);
//	this->setPosition(ccp(startPos.x,startPos.y));
//	
//}
//void SmallWhitePlane::movingToPoint(CCPoint *pos)
//{
//
//}
//void SmallWhitePlane::isDead()
//{
//
//}
//bool SmallWhitePlane::isShowing()
//{
//	
//	return m_planeisShowDis;
//}
//void SmallWhitePlane::updata(float dt)
//{
//	CCLog("SmallWhitePlane::updata");
//	checkPosition(dt);
//	if(isVisible())
//	{
//		checkWeapon(dt);
//	}
//	
//}
//void SmallWhitePlane::checkPosition(float dt)
//{
//	float offSetY = -1;
//	CCLog("SmallWhitePlanePosition.y=%f",getPositionY());
//	setPositionY (getPositionY()+offSetY);
//}
//void SmallWhitePlane::checkWeapon(float dt)
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