#include "stdafx.h"

#include <afx.h>

int main()
{
	//写入文件
	CFile file;
	if(file.Open(_T("test.out"), CFile::modeCreate | CFile::modeWrite))
	{
		char line[256] = "茴香豆的茴";
		file.Write(line, sizeof(line));
		file.Close();
	}

	//读取文件
	if(file.Open(_T("test.out"), CFile::modeRead))
	{
		char line[256];
		if(file.Read(line, 256) != 0)
		{
			printf("%s\r\n", line);
		}

		file.Close();
	}

	return 0;
}