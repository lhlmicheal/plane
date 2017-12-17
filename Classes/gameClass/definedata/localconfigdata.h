#ifndef _LOCALCONFIG_DATA_
#define _LOCALCONFIG_DATA_
#include <vector>
#include "planepropertydata.h"
#include "bulletpropertydata.h"
#define CONFIGPATH "mainLayerUI/"
class LocalConfigData
{
public:
	static LocalConfigData* sharedData();
	void initData();
	vector <PlaneProperty> & planeConfig();
	vector <BulletProperty> & bulletConfig();
	vector <PlaneShowData> & planeShowConfig();
private:
	vector <PlaneProperty> plane;
	vector <BulletProperty> bullet;
	vector <PlaneShowData> planeShow;

};
#endif