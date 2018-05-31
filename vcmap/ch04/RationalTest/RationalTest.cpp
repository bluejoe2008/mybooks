#include "stdafx.h"

#include <iostream>
#include <boost/rational.hpp>

using namespace std;
using namespace boost;

int main()
{
	double a = 1.0 / 3;
	double b = 1.0 / 4;
	
	cout << a << endl;
	cout << b << endl;
	cout << a - b << endl;

	rational<int> ra(1, 3);
	rational<int> rb(1, 4);

	cout << ra << endl;
	cout << rb << endl;
	cout << rational<int>(ra - rb) << endl;

	return 0;
}
