#include "StdAfx.h"
#include "Properties.h"

CProperty * CProperties::getProperty(CString name)
{
	void * pa;
	if(_map.Lookup(name, pa))
		return (CProperty *)pa;

	return NULL;
}

CProperties::~CProperties(void)
{
	POSITION pos;
	CString key;
	void * pa;

	for (pos = _map.GetStartPosition(); pos != NULL;)
	{
	   _map.GetNextAssoc(pos, key, pa);
	   delete pa;
	}
}

int CProperties::loadFrom(ifstream & in)
{
	int lines = 0;

	while(!in.eof())
	{
		//读取其中的一行
		char line[256];
		in.getline(line, 255);
 		
		string s = line;

		//空白行，跳过
		if(s.empty())
			continue;

		//#为注释标记，跳过
		if(s[0] == '#')
			continue;

		//不包含=，跳过
		int i = s.find("=");
		if(i < 0)
			continue;

		//拆分成key=value
		string key = s.substr(0, i);
		string value = s.substr(i + 1);

		_map.SetAt(CString(key.c_str()), new CProperty(CString(value.c_str())));
		lines++;
	}

	return lines;
}
