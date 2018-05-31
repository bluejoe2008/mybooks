#include "stdafx.h"
#include "comutil.h"
#pragma comment( lib, "comsuppw.lib" )

int main()
{
	setlocale(LC_ALL, "chs");

	char s1[] = "中文ABC";
	wchar_t s2[] = L"武林外传";

	//使用xtoy转换
	//s2-->p1
	//第一次调用，计算MBCS字符串字节长度
	int len1 = WideCharToMultiByte(		
		CP_ACP,
		0,
		s2,  						// 宽字符串指针
		sizeof(s2), 				// 宽字符串长度
		NULL,
		0,  						// 参数0表示计算转换后的字符空间
		NULL,
		NULL);

	char * p1 = new char[len1];

	WideCharToMultiByte(
		CP_ACP,
		0,
		s2,  						// 宽字符串指针
		sizeof(s2), 				// 宽字符串长度
		p1,  						// 转换后的字符串指针
		len1, 						// 给出空间大小
		NULL,
		NULL);

	printf("%s\r\n", p1);
	delete [] p1;

	//s1-->p2
	//第一次调用，计算宽字符串字节长度
	int len2 = MultiByteToWideChar(		
		CP_ACP,
		0,
		s1,  						// MBCS字符串指针
		sizeof(s1), 				// MBCS字符串长度
		NULL,
		0);

	wchar_t * p2 = new wchar_t[len2];

	MultiByteToWideChar(
		CP_ACP,
		0,
		s1,  						// MBCS字符串指针
		sizeof(s1), 				// MBCS字符串长度
		p2,  						// 转换后的字符串指针
		len2);

	printf("%S\r\n", p2);
	delete [] p2;

	//使用BSTR完成转换
	_bstr_t bs1(s1);
	_bstr_t bs2(s2);

	char * bp1 = bs2;
	printf("%s\r\n", bp1);
	wchar_t * bp2 = bs1;
	printf("%S\r\n",bp2);

	return 0;
}