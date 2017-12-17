#include "runningscene.h"
#include "../layer/runbglayer.h"
#include "../layer/runplaylayer.h"
#include "../layer/runmainlayer.h"
#include "../manager/audioManager.h"
#include "../manager/UiLayerManager.h"
#include "../manager/planeManager.h"
#include "../helper/gameMainHelper.h"
#include "../manager/bulletManager.h"
#include "../manager/animManager.h"
#include "../manager/boomManager.h"

RunningScene::RunningScene()
	: Scene()
	, mRootlayer(nullptr)
{
}
RunningScene *RunningScene::create()
{
	AudioManager::getInstance()->proloadBackGroundMusic(MUSIC_BG_SENCE_FIHT);
	auto scene = new RunningScene();
	scene->addChild(RunBgLayer::create());

	auto playlayer = RunPlayLayer::create();
	scene->addChild(playlayer);
	auto mainlayer = RunMainLayer::create();
	scene->addChild(mainlayer);
	GameMainHelper::getInstance()->attachMainLayer(mainlayer);
	return scene;
}