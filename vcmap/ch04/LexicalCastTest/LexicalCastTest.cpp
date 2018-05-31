#include "stdafx.h"

#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

int main()
{
	string s = "123";
	int a = lexical_cast<int>(s);
	double b = lexical_cast<double>(s);

	printf("%d\r\n", a + 1);
	printf("%lf\r\n", b + 1);

	try
	{
		int c = lexical_cast<int>("wrong number");
	}
	catch(bad_lexical_cast & e)
	{
		printf("%s\r\n", e.what());
	}

	return 0;
}
