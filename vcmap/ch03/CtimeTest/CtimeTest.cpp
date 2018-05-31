#include "stdafx.h"
#include <ctime>

int main ()
{
	time_t t;
	time(&t);
	tm * pt = localtime(&t);
	printf("%04d-%d-%d %02d:%02d:%02d\r\n", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec);
	printf("%s", asctime(pt));
	tm * pt2 = gmtime(&t);
	printf("%s", asctime(pt2));

	return 0;
}
