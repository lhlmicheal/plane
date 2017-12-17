#include "mainScene.h"
#include "../manager/audioManager.h"
#include "../manager/UiLayerManager.h"
#include "../manager/planeManager.h"

GameMainScene* GameMainScene::create()
{
	auto scene = new GameMainScene();
	auto layer = MainMenuLayer::create();
	scene->addChild(layer);
	return scene;
}
