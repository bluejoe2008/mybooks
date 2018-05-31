#include "stdafx.h"
#include "boost/any.hpp"
#include <string>

using namespace std;
using namespace boost;

class Cat
{
};

void print(any it)
{
	if(it.empty())
	{
		printf("nothing!\r\n");
		return;
	}

	if(it.type() == typeid(int))
	{
		printf("integer: %d\r\n", any_cast<int>(it));
		return;
	}

	if(it.type() == typeid(string))
	{
		printf("string: %s\r\n", any_cast<string>(it).c_str());
		return;
	}

	if(it.type() == typeid(CString))
	{
		_tprintf(_T("CString: %s\r\n"), any_cast<CString>(it));
		return;
	}

	if(it.type() == typeid(Cat))
	{
		_tprintf(_T("oops! a cat!\r\n"));
		return;
	}
}

int main()
{
	print(100);

	any as[] = {any(), 100, string("hello"), CString("world"), Cat()};
	for(int i = 0; i < sizeof(as) / sizeof(as[0]); i++)
	{
		print(as[i]);
	}

	return 0;
}
