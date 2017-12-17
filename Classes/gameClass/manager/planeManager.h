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
	/////���ﲻ��GamePool<PlaneBase>,��������GamePool<PlaneBase*>,��������ΪSprite�࣬�������ÿ������캯���Լ����ƹ��캯���������ݶ���ʱ�򡣻����ʹ�ÿ������ں�����
	/////����ʹ��ָ�����͡� CCSprite::::::CC_DISALLOW_COPY_AND_ASSIGN(Sprite);
	vector<GamePool<PlaneBase*>*> planePool;
	//vector<GamePool<PlaneBase*>*> yellowPlanePool/*;*/
};
#endif