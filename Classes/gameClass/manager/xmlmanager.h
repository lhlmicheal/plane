#ifndef  _LocalXml_Util_h
#define _LocalXml_Util_h
#include "cocos2d.h"
USING_NS_CC;
#include <string>
using namespace std;
class XmlManager
{
public:
	static XmlManager *getInstance();
	CCDictionary * pareseDataFromFile(const string filename);
};
#endif