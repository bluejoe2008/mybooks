// DebugDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

float Divide(int a, int b)
{
	//被除数不能为0
	ASSERT(b != 0);
	return (float)a / b;
}

int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	float c = Divide(a, b);
	printf("%d / %d = %f\r\n", a, b, c);

	return 0;
}
