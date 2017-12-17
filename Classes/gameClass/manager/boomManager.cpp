#include "boomManager.h"
static BoomManager * _boomManager = nullptr;
BoomManager* BoomManager::getInstance()
{
	if(_boomManager == nullptr)
	{
		_boomManager = new BoomManager();
		_boomManager->initBoomPool();
	}
	return _boomManager;
}
void BoomManager::initBoomPool()
{
	boomFactory = new BoomFactory();
	boomtestPool = new GamePool<BoomBasic*>(boomFactory,10,1);
}
BoomBasic* BoomManager::createBoom(int boomtype, Point pos)
{
	int type = boomtype;
	BoomBasic *boomfromPool = nullptr;
	switch(type)
	{
		case BoomType::BOOMTYPE_TEST:
		{
			boomfromPool = boomtestPool->newObjectForTag();
		}
		break;
		case BoomType::BOOMTYPE_TEST2:
		{
		}
		break;
		case BoomType::BOOMTYPE_TEST3:
		{
		}
		break;
		default:
			break;
	}
	return boomfromPool;
}
void BoomManager::preAddBoomToLayer()
{
	if(boomtestPool != nullptr)
	{
		for(int i = 0; i<boomtestPool->m_initialCapacity;i++)
		{
			BoomBasic * boom = boomtestPool->getObjForIndex(i);
			if(!boom->isAdded)
			{
				boom->isAdded = true;
				boom->setVisible(false);
				playLayer->addChild(boom,2);
			}
		}

	}
}
void BoomManager::attachLayer(RunPlayLayer* layer)
{
	playLayer = layer;
	preAddBoomToLayer();
}
void BoomManager::pushBoomPool(BoomBasic *boom)
{
	int boomTag = boom->getBoomTag();
	switch(boomTag)
	{
		case BoomType::BOOMTYPE_TEST:
		{
			boomtestPool->freeOneObject(boom);
		}
		break;
		case BoomType::BOOMTYPE_TEST2:
		{
		}
		break;
		case BoomType::BOOMTYPE_TEST3:
		{
		}
		break;
		default:
			break;
	}
}
void BoomManager::end()
{
	boomtestPool->clearAllArrObject();
}
//vector<GamePool<BoomBasic *>*> boomtestPool;