#include "planeManager.h"
#include "../definedata/LocalConfigData.h"
#include "../helper/gameMainHelper.h"
static PlaneManager* _planemanager = NULL;
 PlaneManager* PlaneManager::getInstance()
 {
	if(_planemanager == NULL)
	{
		_planemanager = new PlaneManager();
	}
	return _planemanager;
 }
void PlaneManager::initPlanes()
{
	factory= new PlaneFactory();
	planePool.push_back(new GamePool<PlaneBase*>(factory,5,planeType::ENEMY_YELLOW));
	planePool.push_back(new GamePool<PlaneBase*>(factory,5,planeType::ENEMY_WHITE));
}
void PlaneManager::updata()
{

}
void PlaneManager::pushPlane(PlaneBase *plane)
{
	int tag = plane->type();
	vector<GamePool<PlaneBase*>*>::iterator it = planePool.begin();
	for(;it!= planePool.end();it++)
	{
		GamePool<PlaneBase*>* poolPlane = *it;
		if(poolPlane->getPoolType() == tag)
		{
			poolPlane->freeOneObject(plane);
		}
	}
}
void PlaneManager::attachLayer(RunPlayLayer *layer)
{
	playlayer = layer;
}
void PlaneManager::showPlane(const PlaneShowData &showData,float hp)
{
	PlaneBase* plane =NULL;
	vector<GamePool<PlaneBase*>*>::iterator it =planePool.begin();
	while(it != planePool.end())
	{
		GamePool<PlaneBase*> * pool = *it;
		if(pool->m_type ==showData.type)
		{
		plane= pool->newObjectForTag();
		if(plane != NULL)
			{
				plane->resetShowData(showData.configPos, hp);
				GameMainHelper::getInstance()->showPlane(plane);
			}
			break;
		}
		it ++;
	}
}
void PlaneManager::end()
{
	/*vector<GamePool<PlaneBase*>*>::iterator it =plantPool.begin();
	while(it != plantPool.end())
	{
		(*it)->clearAllArrObject();
		CC_SAFE_DELETE(*it);
		it++;
	}*/
}