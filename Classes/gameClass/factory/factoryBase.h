#ifndef  _FACTORY_BASE_H
#define _FACTORY_BASE_H
//�����ඨ��Ϊģ���࣬������Ϊ�����࣬�������麯���ӿڡ�

//���Ǹ�������ĳһ���ࣨ����ɻ����ӵ�������������,TΪ�����ͣ���ģ�塣
//ͬʱ��������һ��ͨ�õĽӿ�,�ܴ���ĳ����(������Ƿɻ��๤�������ܴ����ɻ�)
template <class T> class FactoryBase
{
public:
	FactoryBase(){};
	virtual ~FactoryBase(){};//Ϊʲô��Щ�����������麯��
	virtual T  CreateObjectFactory( int type) = 0;//����ķ�������T,�������ò�����֪�������ֹ�����ͬʱ��֪�����Ĳ�Ʒ����
};
#endif