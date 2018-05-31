#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

//累加器
template <typename T>
class Accumulater
{
private:
	int * _count;
	T * _total;
public:
	Accumulater(int * count, T * total)
	{
		_count = count;
		_total = total;
	}

	void operator()(T i)
	{
		(*_count)++;
		(*_total) += i;
	}
};

int main()
{
	//vector
	vector<int> records1;
	for(int i = 0; i < 100; i++)
		records1.push_back(i + 1);

	int count = 0, total = 0;
	Accumulater<int> sum(&count, &total);
	for_each(records1.begin(), records1.end(), sum);
	printf("共统计%d个整数，总和为%d\r\n", count, total);

	//数组
	int records2[100];
	for(int i = 0; i < 100; i++)
		records2[i] = i + 1;

	count = total = 0;
	for_each(records2, records2 + 100, sum);
	printf("共统计%d个整数，总和为%d\r\n", count, total);

	return 0;
}

