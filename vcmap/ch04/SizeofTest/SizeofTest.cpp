#include "stdafx.h"
#include <iostream>

using namespace std;

class Point
{
public:
	double x;
	double y;
};

class Point2
{
public:
	double x;
	double y;
	char z;
};

int _tmain()
{
	Point p1;
	cout << sizeof(p1) << endl;
	cout << sizeof(p1.x) + sizeof(p1.y) << endl;

	Point2 p2;
	cout << sizeof(p2) << endl;
	cout << sizeof(p2.x) + sizeof(p2.y) + sizeof(p2.z) << endl;

	return 0;
}