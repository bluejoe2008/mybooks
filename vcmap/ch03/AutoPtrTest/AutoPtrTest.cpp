#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int * ip = new int;
	auto_ptr<int> aip(ip);

	*ip = 100;
	cout << *aip << endl;

	string * sp = new string("a string");
	auto_ptr<string> asp(sp);

	cout << *asp << endl;
	cout << asp->size() << endl;

	return 0;
}