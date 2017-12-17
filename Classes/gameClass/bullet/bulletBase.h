#ifndef _bullet_base_H
#define _bullet_base_H
#include "cocos2d.h"
USING_NS_CC;
#include "../definedata/bulletpropertydata.h"
class BulletBase: public Sprite
{
public:
	BulletBase();
	BulletBase(const BulletProperty &data);

	///д����ӿ���Ϊ�������Ķ���bulletBase,����Ϊbullet����Ҫ�̵�batchNode��,����BulletBase
	///ҲҪ��sprite

	////д���������ʼ������Ϊ����ӵ��౻�̳��������ഴ���󣬵��ó�ʼ����ҲҪ��bulletBase��ʼ����ccsprite
	virtual bool initWithSpriteFrameName(const std::string &frameName);
	void resetShowBulletData(float datarotat,Point firepos);
	void resetPropetyData();
	virtual void update(float dt);
	virtual void checkPos(float dt);
	void connectEnemy();
	void setHide();
public:
	int rotate;
	Point startPos;
	float speed;
	float power;
	int type;
	bool isShow;
	/////�ӵ�ͼƬ�п��
	float imageWidth;
	float imageHeight;
	bool isAddSheet;//�Ƿ���ӵ�ͼ��;���Ǵ�����ÿ�����͵��ӵ�ֻ�й̶������������ӵ����ظ����õġ�ÿһ���ӵ������ӵ�bulletSheet
								//���Բ��ܱ��ظ����(node addchild()).
	Point targetPos;
	int direction;
private:
	BulletProperty mPropertyData;
};
#endif