#ifndef _gamePool_h
#define _gamePool_h
#include "cocos2d.h"
USING_NS_CC;
#include "../factory/factoryBase.h"
template <class T> class GamePool
{
	/*
	�����أ�ʵ������һ������Ҫ�õ��ķɻ����ӵ����ȶ��ȳ�ʼ���ŵ�һ�������С�
	�õ�һ����ȥ�������õ�һ�����������������ɾ����һ�����������Ӧ������һ֡���ý���ǰ�ӵ���һ���ڵ㱣֤���ô���0�����������������ʱ��ʵ����
	�ְ��������Żص���������һ�����������ظ����á�
	*/
public:
	GamePool(FactoryBase<T> *factory,int capacitynum, int type)//��ʼ����Ϸ��
	{
		this->m_initialCapacity = capacitynum;
		this->m_type =type;
		this->m_factory = factory;
		initPool(m_initialCapacity,m_type);
	
	}
	~GamePool();
	/////////�ӳ��л�ȡ����
	T getObjForIndex(int index)
	{
		T object;
		object = (T)m_freeObject->objectAtIndex(index);
		return object;
	}
	T newObjectForTag()
	{
		//�������������У��Ͳ��÷����µĶ���
		if(! m_freeObject->count())
		{
			return NULL;//��
		}
		////
		T object = (T)m_freeObject->objectAtIndex(0);
		m_freeObject->removeObjectAtIndex(0);
		return object;
	}
	////////����ػ���
	void clearAllArrObject()
	{
		m_freeObject->removeAllObjects();
		m_freeObject->release();//�ֶ��ͷ�����
	}
	///////////���ճ��ж���
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
		m_freeObject->retain();//��������,��Ȼ��֡���ý������ᱻ�ͷš�
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
	int m_initialCapacity;//��ʼ������
	int m_type;//������
private:
	FactoryBase<T> *m_factory;
	CCArray *m_freeObject;
};

#endif