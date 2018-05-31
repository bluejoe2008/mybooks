#include "stdafx.h"
#include <cstdio>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "chs");

	//写入文件
	FILE * fp = _wfopen(L"test.out", L"w,ccs=UNICODE");
	fwprintf(fp, L"%s", L"茴香豆的茴");
	fclose(fp);

	//读取文件
	fp = _wfopen(L"test.out", L"r,ccs=UNICODE");
	wchar_t line[256];
	fwscanf(fp, L"%s", line);
	wprintf(L"%s\r\n", line);
	fclose(fp);

	return 0;
}