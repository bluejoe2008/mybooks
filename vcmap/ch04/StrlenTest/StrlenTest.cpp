#include "stdafx.h"
#include "string"
#include "comutil.h"
#pragma comment( lib, "comsuppw.lib" )

using namespace std;

int main()
{
	char s1[] = "中文ABC";
	wchar_t s2[] = L"中文ABC";

	//使用sizeof获取字符串长度
	printf("sizeof s1: %d\r\n", sizeof(s1));
	printf("sizeof s2: %d\r\n", sizeof(s2));

	//使用strlen获取字符串长度
	printf("strlen(s1): %d\r\n", strlen(s1));
	printf("wcslen(s2): %d\r\n", wcslen(s2));

	//使用CString::GetLength()获取字符串长度
	CStringA sa = s1;
	CStringW sw = s2;

	printf("sa.GetLength(): %d\r\n", sa.GetLength());
	printf("sw.GetLength(): %d\r\n", sw.GetLength());

	//使用string::size()获取字符串长度
	string ss1 = s1;
	wstring ss2 = s2;

	printf("ss1.size(): %d\r\n", ss1.size());
	printf("ss2.size(): %d\r\n", ss2.size());

	//使用_bstr_t::length()获取字符串长度
	_bstr_t bs1(s1);
	_bstr_t bs2(s2);

	printf("bs1.length(): %d\r\n", bs1.length());
	printf("bs2.length(): %d\r\n", bs2.length());

	return 0;
}