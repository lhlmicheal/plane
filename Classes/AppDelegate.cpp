#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "./gameClass/scene/mainScene.h"
#include "./gameClass/manager/uilayermanager.h"
#include "./gameClass/manager/audioManager.h"
#include "./gameClass/manager/planeManager.h"
#include "./gameClass/helper/gameMainHelper.h"
#include "./gameClass/manager/bulletManager.h"
#include <stdio.h>
#include <stdlib.h>
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
	
	
	//ģ���豸�ֱ���
	//glview->setFrameSize(480,800);

	//���Ʒֱ��ʣ�setdesignResolutionSize()����ǰ����ֵ���ݸ�direction.winsize����Ϊ���Ʒֱ���
	//���ǵ�ͼƬ���Ƶ���480*800

	//������ʵ�豸�ķֱ���
	auto DeviceView =  glview->getFrameSize();


	CCSize desigBaseSize= CCSize(480,800);
	//��������ѡ��NO_BORDER ,��Ϊ��Ļ���䷽���������������� widrate = decvice.width/���Ʒֱ���.size ,heightRate = device.height/���Ʒֱ���.size.height
	//�����������������ģ�Ҳ����������device�У��Ǹ�ȥ���롣��������һ��ҲҪ������ô�������������Ĳ��־ʹ�����Ұ֮���ˡ�
	//
	float widRate = DeviceView.width/desigBaseSize.width;
	float heightRate = DeviceView.height/desigBaseSize.height;
	glview->setDesignResolutionSize(desigBaseSize.width,desigBaseSize.height,ResolutionPolicy::SHOW_ALL);
	//if(widRate > heightRate)
	//{
	//˵������NO_BORDER���������Ȼ����룬�߶Ȼᳬ����Ұ֮��;
		glview->setDesignResolutionSize(desigBaseSize.width,desigBaseSize.height,ResolutionPolicy::SHOW_ALL);
	//}
	//else
	//{
		//glview->setDesignResolutionSize(desigBaseSize.width,desigBaseSize.height,ResolutionPolicy::NO_BORDER);
	//}
	

	CCSize framesize = glview->getFrameSize();
	CCLog("openGl.width=%f,openGl.heinght=%f",framesize.width,framesize.height);
    // turn on display FPS
    director->setDisplayStats(true);

	CCSize winsize = director->getWinSize();
	CCLog("winsize.width = %f,winsize.height=%f ",winsize.width,winsize.height);

	CCPoint orgsize = director->getVisibleOrigin();
	CCLog("orgsize.x = %f,orgsize.y=%f ",orgsize.x,orgsize.y);

	CCSize visibleSize = director->getVisibleSize();
	CCLog("visibleSize.width = %f,visibleSize.height=%f ",visibleSize.width,visibleSize.height);

	
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
   // auto scene = HelloWorld::createScene();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/gameBtn.plist","mainLayerUI/gameBtn.png"
		);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/gameIcon.plist","mainLayerUI/gameIcon.png"
		);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/gameHero.plist","mainLayerUI/gameHero.png"
		);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainLayerUI/bullettp.plist","mainLayerUI/bullettp.png");

	AudioManager::getInstance()->proloadBackGroundMusic(MUSIC_BG_SENCE_UI);
	auto scene = GameMainScene::create();
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
