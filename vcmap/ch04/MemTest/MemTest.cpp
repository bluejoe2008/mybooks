#include "stdafx.h"
#include <cstring>

int main()
{
	char a[11];
	char b[21];

	memset(a, 'A', sizeof(a));
	//结束符
	a[sizeof(a) - 1] = 0;

	memset(b, 'B', sizeof(b));
	//结束符
	b[sizeof(b) - 1] = 0;

	//创建一个30字节的字符数组
	char * cp = new char[sizeof(a) + sizeof(b) - 1];

	//合并
	memcpy(cp, a, sizeof(a) - 1);
	memcpy(cp + sizeof(a) - 1, b, sizeof(b) - 1);

	//结束符
	cp[sizeof(a) + sizeof(b) - 2] = 0;

	//合并完毕，输出
	printf("%s\r\n", a);
	printf("%s\r\n", b);
	printf("%s\r\n", cp);
}

