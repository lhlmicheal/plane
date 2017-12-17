#ifndef _BoomTest_H
#define _BoomTest_H
#include "boomBasic.h"
#include <string>
using namespace std;
class BoomTest:public BoomBasic
{
public:
	BoomTest();
	BoomTest(int type);
	~BoomTest();
	static BoomTest * createBoomTestWithFileName(string &filename,int type);
public:
	virtual void initSpWithName(string filename);
	virtual void boomShow(CCPoint pos);
	virtual void startPlayBoomAnima();
	virtual void finishPlayBoomAnima();
private:

};
#endif