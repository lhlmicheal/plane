#ifndef  _FACTORY_BASE_H
#define _FACTORY_BASE_H
//将此类定义为模板类，并定义为纯虚类，给出纯虚函数接口。

//我们给出它是某一种类（比如飞机，子弹，卡车，武器,T为类类型）的模板。
//同时给出他有一个通用的接口,能创造某种类(如果它是飞机类工厂，他能创建飞机)
template <class T> class FactoryBase
{
public:
	FactoryBase(){};
	virtual ~FactoryBase(){};//为什么有些析构函数是虚函数
	virtual T  CreateObjectFactory( int type) = 0;//这里的返回类型T,两个作用不仅告知了是那种工厂，同时告知生产的产品类型
};
#endif