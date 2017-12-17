#ifndef _gamePool_h
#define _gamePool_h
#include "cocos2d.h"
USING_NS_CC;
#include "../factory/factoryBase.h"
template <class T> class GamePool
{
	/*
	容量池：实际上用一个数组要用到的飞机，子弹，等都先初始化放到一个数组中。
	用到一个就去数组中拿第一个，并立马从数组中删除第一个（这个对象应该在这一帧调用结束前加到另一个节点保证引用大于0）。当回收这个对象时。实际上
	又把这个对象放回到数组的最后一个。这样能重复利用。
	*/
public:
	GamePool(FactoryBase<T> *factory,int capacitynum, int type)//初始化游戏池
	{
		this->m_initialCapacity = capacitynum;
		this->m_type =type;
		this->m_factory = factory;
		initPool(m_initialCapacity,m_type);
	
	}
	~GamePool();
	/////////从池中获取对象
	T getObjForIndex(int index)
	{
		T object;
		object = (T)m_freeObject->objectAtIndex(index);
		return object;
	}
	T newObjectForTag()
	{
		//如果缓存池数组有，就不用返回新的对象
		if(! m_freeObject->count())
		{
			return NULL;//空
		}
		////
		T object = (T)m_freeObject->objectAtIndex(0);
		m_freeObject->removeObjectAtIndex(0);
		return object;
	}
	////////清除池缓存
	void clearAllArrObject()
	{
		m_freeObject->removeAllObjects();
		m_freeObject->release();//手动释放引用
	}
	///////////回收池中对象
	void freeOneObject( T object)
	{
		m_freeObject->addObject(object);
	}
	void freeAllArrObject( CCArray *arrObject)
	{
		int size = arrObject->count();
		for(int i =0; i< size;i++)
		{
			m_freeObject->addObject(arrObject->getObjectAtIndex(i));
		}
		arrObject->removeAllObjects();
	}
	void initPool(int capacitynum,int type)
	{
		m_freeObject = CCArray::create();
		m_freeObject->retain();//保持引用,不然改帧调用结束，会被释放。
		for(int i = 0; i <capacitynum; i++)
		{
			T object = m_factory->CreateObjectFactory(type);
			m_freeObject->addObject(object);
		}
	}
	int getPoolType()
	{
		return m_type;
	}
	int m_initialCapacity;//初始化容量
	int m_type;//池类型
private:
	FactoryBase<T> *m_factory;
	CCArray *m_freeObject;
};

#endif