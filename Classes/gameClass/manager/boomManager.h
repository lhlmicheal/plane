#ifndef _boomManager_H
#define _boomManager_H
#include <vector>+
#include "../boom/boomBasic.h"
#include "../pool/gamePool.h"
#include "../factory/boomFactory.h"
#include "../layer/runplaylayer.h"
class BoomManager{
public:
	BoomManager(){};
	~BoomManager(){};
	static BoomManager *getInstance();
public:
	RunPlayLayer *playLayer;
	BoomFactory *boomFactory;
	GamePool<BoomBasic *>* boomtestPool;

	void initBoomPool();
	void preAddBoomToLayer();
	void attachLayer(RunPlayLayer* layer);
	BoomBasic* createBoom(int boomtype, Point pos = Point::ZERO);
	void pushBoomPool(BoomBasic *boom);
	void end();
	
};
#endif