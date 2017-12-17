#ifndef UIPOP_MANAGER_H
#define UIPOP_MANAGER_H
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class UiLayerManager
{
public:
	static UiLayerManager* getInstance();
	UiLayerManager();
	~UiLayerManager();
	void addPopLayer(Layer* layer);
	void addPopAndRemoveCureLayer(Layer* layer);
	void removeLayer(Layer* layer);
	void removeAllLayer();
	Layer* getCurLayer();
private:
	vector<Layer*> mLayers;
	Layer *mCurLayer;
};
#endif