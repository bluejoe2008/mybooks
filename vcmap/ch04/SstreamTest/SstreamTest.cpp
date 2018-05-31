#include "stdafx.h"

#include <iostream>
#include <sstream>
using namespace std;

int main ()
{
	int i1, i2;
	i1 = 100;
	i2 = 200;

	//int --> string
	ostringstream out;
	out << i1 << " " << i2;

	string s = out.str();
	cout << "string: " << s << endl;

	//string --> double
	double chinese, math;
	istringstream in(s);
	in >> chinese >> math;

	cout << "chinese:" << chinese << endl;
	cout << "math:" << math << endl;

	return 0;
}
