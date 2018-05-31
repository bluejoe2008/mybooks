#include "stdafx.h"
#include "math.h"

CMath::CMath(int a, int b)
{
	_a = a;
	_b = b;
}

int CMath::_mcd(int a, int b)
{
	if (b == 0)
		return a;

	return _mcd(b, a % b);
}

int CMath::mcd()
{
	return _mcd(_a, _b);
}

int CMath::_lcm(int a, int b)
{
	return a * b / _mcd(b, a % b);
}

int CMath::lcm()
{
	return _lcm(_a, _b);
}