#include "stdafx.h"

//求最大公约数
int mcd(int a, int b)
{
	if (b == 0)
		return a;

	return mcd(b, a % b);
}
