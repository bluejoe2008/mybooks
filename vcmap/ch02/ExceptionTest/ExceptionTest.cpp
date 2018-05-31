// DebugDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//被0除的异常
class DividedByZero
{
};

//超出范围
class OutOfRange
{
};

float Divide(int a, int b)
{
	if(b == 0)
		throw DividedByZero();

	if(b < 0)
		throw OutOfRange();

	return (float)a / b;
}

int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	try
	{
		float c = Divide(a, b);
		printf("%d / %d = %f\r\n", a, b, c);
	}
	catch(DividedByZero & e)
	{
		printf("执行除法时发生被0除错误！\r\n");
	}
	catch(...)
	{
		printf("执行除法时发生错误！\r\n");
	}

	return 0;
}
