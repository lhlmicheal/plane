#ifndef _AnimaManager_H_
#define _AnimaManager_H_
#include "cocos2d.h"
USING_NS_CC;
#include <string>
using namespace std;
class MyManagerAnimation
{
public:
    MyManagerAnimation();
    ~MyManagerAnimation();
    static MyManagerAnimation *getInstance();
    AnimationCache * anicache;
public:
    void init();
    void addAnimationWithFileAndName(string filename, string aniName);
    Animation* getAnimationName(string animaName);
};




#endif