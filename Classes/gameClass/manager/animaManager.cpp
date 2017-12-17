#include "animManager.h"
#define ANIMAPLIATPATH  "mainLayerUI/"
static MyManagerAnimation* _managerAnima = nullptr;
MyManagerAnimation::MyManagerAnimation()
{

}
MyManagerAnimation::~MyManagerAnimation()
{
    SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("mainLayerUI/gameBoom.plist");
}

MyManagerAnimation* MyManagerAnimation::getInstance()
{
    if(_managerAnima == nullptr)
    {
        _managerAnima = new MyManagerAnimation();
        _managerAnima->init();
        
    }
    return _managerAnima;
}
void MyManagerAnimation::init()
{
    anicache = AnimationCache::getInstance();
}
void MyManagerAnimation::addAnimationWithFileAndName(string filename,string aniName)
{
    string fullPath = ANIMAPLIATPATH +filename;
    CCLOG("MyManagerAnimation:addAnimationPlistwithFile:fullpath=%s",fullPath.c_str());
    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile(fullPath);
    
    Vector<SpriteFrame*> arrFrame;
    char str[100] = {0};
    string framestr = aniName;
    for (int i = 1; i <=15;i++) {
        framestr = aniName;
        sprintf(str, "(%d).png",i);
        framestr += string(str);
        CCLOG("frameStr =%s",framestr.c_str());
        SpriteFrame *frame = frameCache->getSpriteFrameByName(framestr);
        arrFrame.pushBack(frame);
    }
    
    auto stoneAnim = Animation::createWithSpriteFrames(arrFrame, 0.1);
    
    anicache->addAnimation(stoneAnim, aniName);
    Animation * ani = anicache->getAnimation(aniName);
    
    ani->setRestoreOriginalFrame(true);

    
    
}
Animation* MyManagerAnimation::getAnimationName(string name)
{
    Animation  *a=  anicache->getAnimation(name);
    return a;
}