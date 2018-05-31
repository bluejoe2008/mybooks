#include "stdafx.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(0));
	
	for(int i = 0; i < 5; i++)
		printf("%d\r\n", rand());

	return 0;
}