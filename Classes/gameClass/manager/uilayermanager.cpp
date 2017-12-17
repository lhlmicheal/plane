#include "UiLayerManager.h"
#include "../scene/mainScene.h"
static UiLayerManager* _uilayermanager = NULL;
UiLayerManager * UiLayerManager::getInstance()
{
	if(_uilayermanager == NULL)
	{
		_uilayermanager = new UiLayerManager();
	}
	return _uilayermanager;
}
UiLayerManager::UiLayerManager()
{
		mCurLayer = nullptr;
}
UiLayerManager::~UiLayerManager()
{
	if(_uilayermanager != NULL)
	{
		delete _uilayermanager;
		_uilayermanager = NULL;
	}
}
///////////增加layer
void UiLayerManager::addPopLayer(Layer* layer)
{
	if(!layer) return;
	mLayers.push_back(layer);
	Scene *curScene = CCDirector::getInstance()->getRunningScene();
	curScene->addChild(layer);
	mCurLayer = layer;
}
void UiLayerManager::addPopAndRemoveCureLayer(Layer* layer)
{
	if(!layer) return;
	if(!mCurLayer) removeLayer(mCurLayer);
	addPopLayer(layer);
}
	//////////移除layer
void UiLayerManager::removeLayer(Layer* layer)
{
	if(!layer) return;
	auto it = mLayers.begin();
	for(; it != mLayers.end(); it++)
	{
		if(*it == mCurLayer)
		{
				mLayers.erase(it);
				break;
		}
	}
	Scene *curScene = CCDirector::getInstance()->getRunningScene();
	curScene->removeChild(layer);
}
void UiLayerManager::removeAllLayer()
{
	Scene *curScene = CCDirector::getInstance()->getRunningScene();
	for (auto it = mLayers.begin(); it != mLayers.end(); )
	{
		curScene->removeChild(*it,true);
	}
	mLayers.clear();
}
Layer* UiLayerManager::getCurLayer()
{
	return mCurLayer;
}