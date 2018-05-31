#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//写入文件
	ofstream out("test.out");
	out << "茴香豆的茴";
	out.close();

	//读取文件
	ifstream in("test.out");
	char line[256];
	in.getline(line, 256);
	cout << line << endl;

	return 0;
}
