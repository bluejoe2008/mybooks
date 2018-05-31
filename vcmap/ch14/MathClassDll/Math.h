#pragma once

class _declspec(dllexport) CMath
{
private:
	int _a;
	int _b;
	int _mcd(int a, int b);
	int _lcm(int a, int b);
public:
	CMath(int a, int b);
	int mcd();
	int lcm();
};
