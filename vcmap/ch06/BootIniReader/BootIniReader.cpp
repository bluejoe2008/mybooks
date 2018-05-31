#include "stdafx.h"

int _tmain()
{
	TCHAR buffer[256];
	TCHAR path[] = _T("c:\\boot.ini");
	int len = GetPrivateProfileSectionNames(buffer, sizeof(buffer), path);

	TCHAR *names = buffer;
	TCHAR *end = names + len;

	//返回的sectionNames以null分隔

	while(names < end)
	{
		CString name = names;
		_tprintf(_T("======%s======\r\n"), name);
		names += name.GetLength();
		names ++;

		//获取该section下面所有的属性
		TCHAR buffer2[1024];
		len = GetPrivateProfileSection(name, buffer2, sizeof(buffer2), path);
		//遍历所有行
		TCHAR *lines = buffer2;
		while(*lines)
		{
			CString line = lines; 
			_tprintf(_T("\t%s\r\n"), line);

			lines += line.GetLength();
			lines ++;
		}
	}

	return 0;
}