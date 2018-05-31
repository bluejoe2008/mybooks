// CMathTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cmath>

int main()
{
	double pi = 3.14159;
	double alpha = pi / 6;

	double sina = sin(alpha);
	double cosa = cos(alpha);
	double tana = tan(alpha);
	double asina = asin(alpha);

	printf("alpha = %lf\r\n", alpha);
	printf("sina = %lf, cosa = %lf, tana = %lf, asina = %lf\r\n", sina, cosa, tana, asina);
	printf("sina^2 + cosa^2 = %lf\r\n", sina * sina + cosa * cosa);
	printf("asin(sina) = %lf\r\n", asin(sina));
	printf("sina / cosa = %lf\r\n", sina / cosa);

	return 0;
}

