#include "boomTest.h"
#include "../manager/animManager.h"
BoomTest::BoomTest()
{
}
BoomTest::~BoomTest()
{
}
BoomTest::BoomTest(int type):BoomBasic(type)
{

}
 BoomTest * BoomTest::createBoomTestWithFileName(string &filename,int type)
 {
	 BoomTest * boom = new BoomTest(type);
	 boom->initSpWithName(filename);
	 return boom;
 }
 void BoomTest::initSpWithName(string filename)
 {
	 BoomBasic::initSpWithName(filename);
 }
void BoomTest::boomShow(CCPoint pos)
{
	  BoomBasic::boomShow(pos);
	  setPosition(pos);
	  startPlayBoomAnima();
}
 void BoomTest::startPlayBoomAnima()
{
	Animation *ani = MyManagerAnimation::getInstance()->getAnimationName("boom");
	Animate *aniAct = Animate::create(ani);
	setVisible(true);
	this->runAction(Sequence::create(aniAct,CallFunc::create(this,callfunc_selector(BoomTest::finishPlayBoomAnima)),NULL));
}
void BoomTest::finishPlayBoomAnima()
{
	BoomBasic::finishPlayBoomAnima();
}
