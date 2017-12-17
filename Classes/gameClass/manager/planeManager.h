#ifndef _planeManager_h
#define _planeManager_h
#include <vector>
using namespace std;
#include "../pool/gamePool.h"
#include "../plane/planeBase.h"
#include "../factory/planeFactory.h"
#include "../layer/runplaylayer.h"
#include "../definedata/LocalConfigData.h"
class PlaneManager
{
public:
	PlaneFactory *factory;
	RunPlayLayer *playlayer;
	static PlaneManager* getInstance();

public:
	void initPlanes();
	void updata();
	void pushPlane(PlaneBase *plane);
	void attachLayer(RunPlayLayer *layer);
	void showPlane(const PlaneShowData &data,float hp);
	void end();
	/////这里不用GamePool<PlaneBase>,而是用了GamePool<PlaneBase*>,可能是因为Sprite类，不允许用拷贝构造函数以及复制构造函数，当传递对象时候。会造成使用拷贝狗在函数。
	/////所以使用指针类型。 CCSprite::::::CC_DISALLOW_COPY_AND_ASSIGN(Sprite);
	vector<GamePool<PlaneBase*>*> planePool;
	//vector<GamePool<PlaneBase*>*> yellowPlanePool/*;*/
};
#endif