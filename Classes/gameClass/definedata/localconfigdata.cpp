#include "localconfigdata.h"
#include "../manager/xmlmanager.h"
#include "bulletpropertydata.h"
#include "globalData.h"
static LocalConfigData *_mLocalConfigData =NULL;
 LocalConfigData* LocalConfigData::sharedData()
 {
	 if(_mLocalConfigData == NULL)
	 {
		 _mLocalConfigData = new LocalConfigData();
		 _mLocalConfigData->initData();
	 }
	 return _mLocalConfigData;
 }
void LocalConfigData::initData()
{
	//读取配置文件
	CCDictionary *filedict =  XmlManager::getInstance()->pareseDataFromFile("config/gameLoaclConfig.xml");
	CCDictionary *enemydict = CCDictionary::create();
	enemydict = (CCDictionary*) filedict->objectForKey("enemyPlane");
	int count = enemydict->valueForKey ("enemyTypeCount")->intValue();
	string tempstr = "";
	//读取飞机配置数据
	for(int i = 1; i<=count;i++)
	{
		tempstr = "";
		tempstr = CCString::createWithFormat("smallPlane%d",i)->getCString();
		if(enemydict->objectForKey(tempstr))
		{
			CCDictionary* planedicData =(CCDictionary*) enemydict->objectForKey(tempstr);
			PlaneProperty  dataplane;
			dataplane.type = planedicData->valueForKey("type")->intValue();
			dataplane.speed = planedicData->valueForKey("speed")->intValue();
			dataplane.hp = planedicData->valueForKey("life")->intValue();
			dataplane.texturename = planedicData->valueForKey("textureImage")->getCString();
			dataplane.score= planedicData->valueForKey("score")->intValue();
			dataplane.weaponTag = planedicData->valueForKey("weaponTag")->intValue();
			plane.push_back(dataplane);
		}
	}
	//读取子弹配置数据
	CCDictionary *bulletdict = CCDictionary::create();
	bulletdict = (CCDictionary*) filedict->objectForKey("bulletInfo");
	int bulletcount = bulletdict->valueForKey ("bulletTypeCount")->intValue();
	 tempstr = "";
	for(int i = 1; i<=bulletcount;i++)
	{
		tempstr = "";
		tempstr = CCString::createWithFormat("bullettype%d",i)->getCString();
		if(bulletdict->objectForKey(tempstr))
		{
			CCDictionary* bulletdictData =(CCDictionary*) bulletdict->objectForKey(tempstr);
			BulletProperty  dataBullet;
			dataBullet.type = bulletdictData->valueForKey("type")->intValue();
			dataBullet.speed = bulletdictData->valueForKey("speed")->intValue();
			dataBullet.picname= bulletdictData->valueForKey("textureImage")->getCString();
			dataBullet.power = bulletdictData->valueForKey("power")->intValue();
			bullet.push_back(dataBullet);
		}
	}
	//PlaneMapData//飞机出现位置
	CCArray *planeMap = CCArray::create();
	planeMap = (CCArray*) filedict->objectForKey("disPlayInfo");
	for(int m =0; m<planeMap->count();m++)
	{
		PlaneShowData data;
		CCString* pi_string = (CCString*)planeMap->objectAtIndex(m);
		string org_string = pi_string->getCString();
		vector<string> str_arr =GlobalData::sharedData()->splitStringWithLimit(org_string,",");
		data.type = atoi(str_arr[0].c_str());
		data.configPos.x = atoi(str_arr[1].c_str());
		data.configPos.y = atoi(str_arr[2].c_str());
		data.showDis= atoi(str_arr[3].c_str());
		planeShow.push_back(data);
	}
}
vector <PlaneProperty> & LocalConfigData::planeConfig()
{
	return plane;
}
vector <BulletProperty> & LocalConfigData::bulletConfig()
{
	return bullet;
}
vector <PlaneShowData> & LocalConfigData::planeShowConfig()
{
	return planeShow;
}