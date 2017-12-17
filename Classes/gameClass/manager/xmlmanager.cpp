#include "xmlmanager.h"
static XmlManager * m_xml =NULL;
XmlManager *XmlManager::getInstance()
{
	if(m_xml == NULL)
	{
		m_xml = new XmlManager();
	}
	return m_xml;
}
CCDictionary * XmlManager::pareseDataFromFile(const string filename)
{
	bool isExist = CCFileUtils::getInstance()->isFileExist(filename);
	if(!isExist)
	{
		CCAssert(isExist,"XmlManager::pareseDataFromFile no Found file");
	}
	CCDictionary *pct =CCDictionary::createWithContentsOfFile(filename.c_str());
	return pct;
}