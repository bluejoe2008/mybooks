#include "stdafx.h"
#include <iostream>
using namespace std;

struct RGB
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

union COLOR
{
	unsigned int value;
	RGB rgb;
};

int _tmain()
{
	COLOR c = {0xFF8844};
	cout << hex << (int)c.rgb.red << "," << (int)c.rgb.green << "," << (int)c.rgb.blue << endl;
	cout << &c.value << "," << &c.rgb << endl;

	return 0;
}