#ifndef _BULLETPROPERTY_H
#define _BULLETPROPERTY_H
#include <string>
using namespace std;
class BulletProperty
{
public:
	int type;
	int power;
	float speed;
	string picname;
	BulletProperty()
	{
		type = -1;
		picname = "";
		power = 0;
		speed = 0;
	}
};
#endif