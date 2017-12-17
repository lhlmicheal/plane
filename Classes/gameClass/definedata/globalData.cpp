#include "globalData.h"
static GlobalData* _golbaldata_shared = NULL;
float GlobalData::arrsin[]={
0.0174
,0.0348
,0.0523
,0.0697
,0.0871
,0.1045
,0.1218
,0.1391
,0.1564
,0.1736
,0.1908
,0.2079
,0.2249
,0.2419
,0.2588
,0.2756
,0.2923
,0.3090
,0.3255
,0.3420
,0.3583
,0.3746
,0.3907
,0.4067
,0.4226
,0.4383
,0.4539
,0.4694
,0.4848
,0.5000
,0.5150
,0.5299
,0.5446
,0.5591
,0.5735
,0.5877
,0.6018
,0.6156
,0.6293
,0.6427
,0.6560
,0.6691
,0.6819
,0.6946
,0.7071
,0.7193
,0.7313
,0.7431
,0.7547
,0.7660
,0.7771
,0.7880
,0.7986
,0.8090
,0.8191
,0.8290
,0.8386
,0.8480
,0.8571
,0.8660
,0.8746
,0.8829
,0.8910
,0.8987
,0.9063
,0.9135
,0.9205
,0.9271
,0.9335
,0.9396
,0.9455
,0.9510
,0.9563
,0.9612
,0.9659
,0.9702
,0.9743
,0.9781
,0.9816
,0.9848
,0.9876
,0.9902
,0.9925
,0.9945
,0.9961
,0.9975
,0.9986
,0.9993
,0.9998
,1.0000
};
float GlobalData::arrcos[]={
0.99984
,0.99939
,0.99862
,0.99756
,0.99619
,0.99452
,0.99254
,0.99026
,0.98768
,0.98480
,0.98162
,0.97814
,0.97437
,0.97029
,0.96592
,0.96126
,0.95630
,0.95105
,0.94551
,0.93969
,0.93358
,0.92718
,0.92050
,0.91354
,0.90630
,0.89879
,0.89100
,0.88294
,0.87461
,0.86602
,0.85716
,0.84804
,0.83867
,0.82903
,0.81915
,0.80901
,0.79863
,0.78801
,0.77714
,0.76604
,0.75470
,0.74314
,0.73135
,0.71933
,0.70710
,0.69465
,0.68199
,0.66913
,0.65605
,0.64278
,0.62932
,0.61566
,0.60181
,0.58778
,0.57357
,0.55919
,0.54463
,0.52991
,0.51503
,0.50000
,0.48480
,0.46947
,0.45399
,0.43837
,0.42261
,0.40673
,0.39073
,0.37460
,0.35836
,0.34202
,0.32556
,0.30901
,0.29237
,0.27563
,0.25881
,0.24192
,0.22495
,0.20791
,0.19080
,0.17364
,0.15643
,0.13917
,0.12186
,0.10452
,0.08715
,0.06975
,0.05233
,0.03489
,0.01745
,0.0001
};
GlobalData* GlobalData::sharedData()
{
	if(_golbaldata_shared == NULL)
	{
		_golbaldata_shared = new GlobalData();
		_golbaldata_shared->initData();
	}
	return _golbaldata_shared;
}
void GlobalData::initData()
{
	m_score = 0;
}
void GlobalData::setScore(int score)
{
	m_score = score;
}
int GlobalData::getScore()
{
  return m_score;
}
bool GlobalData::isOutScreen(PlaneBase *obj)
{
	bool outscreen = false;
	//CCLog("GlobalData::obj.pos.x=%f,obj.pos.y=%f",obj->getPositionX(),obj->getPositionY());
	//左右边界
	if((obj->getPositionX()+obj->getContentSize().width/2) <= DEVIATION || (obj->getPositionX()- obj->getContentSize().width/2) >= (GAME_WIDTH))
	{
		outscreen = true;
	}
	//上下边界
	if( (obj->getPositionY() +obj->getContentSize().height/2 ) <= DEVIATION || (obj->getPositionY() - obj->getContentSize().width/2 ) >= (GAME_HIGHT))
	{
		outscreen = true;
	}
	return outscreen;
}
bool GlobalData::isOutScreen(BulletBase *obj)
{
	bool outscreen = false;
	//CCLog("GlobalData::obj.pos.x=%f,obj.pos.y=%f",obj->getPositionX(),obj->getPositionY());
	//左右边界
	if((obj->getPositionX()+obj->getContentSize().width/2) <= DEVIATION || (obj->getPositionX()- obj->getContentSize().width/2) >(GAME_WIDTH))
	{
		outscreen = true;
	}
	//上下边界
	if( (obj->getPositionY() +obj->getContentSize().height/2 )<= DEVIATION || (obj->getPositionY() - obj->getContentSize().width/2 )> (GAME_HIGHT))
	{
		outscreen = true;
	}
	return outscreen;
}
std::vector<string> GlobalData::splitStringWithLimit(string str,string limit)
{
	std::string::size_type pos;
  std::vector<std::string> result;
  str+=limit;//扩展字符串以方便操作
  int size=str.size();
 
  for(int i=0; i<size; i++)
  {
    pos=str.find(limit,i);
    if(pos<size)
    {
      std::string s=str.substr(i,pos-i);
      result.push_back(s);
      i=pos+limit.size()-1;
    }
  }
  return result;
}

float GlobalData::getRotateTwoPoint(Point sef,Point tar)
{
	float angle = 0;
	float len_x =abs( tar.x -sef.x);
	float len_y =abs( tar.y -sef.y);
	double tan_yx = abs(len_y/len_x);
	CCLog("tan_yx: %f. aTanyx : %f",tan_yx,atan(tan_yx));
	if(tar.x > sef.x && tar.y >sef.y)
	{//目标点在右上角
		CCLog("###目标点在右上角RU###");
		angle = 90 - atan(tan_yx) *(180/SHAPER_PI);
	}
	else if(tar.x > sef.x && tar.y <sef.y)
	{//目标点在右下角
		CCLog("###目标点在右下角RD###");
		angle = 90 + atan (tan_yx) *(180/SHAPER_PI);
	}
	else if(tar.x < sef.x && tar.y >sef.y)
	{//目标点在左上角
		CCLog("###目标点在左上角LU###");
		angle =   atan(tan_yx) *(180/SHAPER_PI) -90;
	}
	else if(tar.x < sef.x && tar.y <sef.y)
	{//目标点在左下角
		CCLog("###目标点在左下角LD###");
		angle = -90 -  atan(tan_yx) *(180/SHAPER_PI) ;
	}
	return angle;
}