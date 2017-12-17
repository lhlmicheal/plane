#include "boomBasic.h"
#include "../manager/animManager.h"
BoomBasic::BoomBasic()
{

}
BoomBasic::~BoomBasic()
{
}
BoomBasic::BoomBasic(int tag)
{
 boom_tag = tag;
 isShow = false;
 isAdded = false;
}

int BoomBasic::getBoomTag()
{
	return boom_tag;
}
void BoomBasic::boomShow(CCPoint pos)
{
	isShow = true;
	startPlayBoomAnima();
}
void BoomBasic::finishPlayBoomAnima()
{
	isShow = false;
	setVisible(false);
}
void  BoomBasic::initSpWithName(string filename)
{
	Sprite::initWithSpriteFrameName(filename);
}