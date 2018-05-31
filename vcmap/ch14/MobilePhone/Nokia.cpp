#include "stdafx.h"
#include "Nokia.h"

NokiaMobilePhone::NokiaMobilePhone()
{
	cout << "欢迎使用诺基亚！" << endl;
}

NokiaMobilePhone::~NokiaMobilePhone()
{
	cout << "再见！" << endl;
}

void NokiaMobilePhone::dial(string number)
{
	cout << number << endl;
	cout << "电话已拨通..." << endl;
}

void NokiaMobilePhone::talk()
{
	cout << "blablabla~~~~" << endl;
}

void NokiaMobilePhone::hangup()
{
	cout << "已正常挂断！" << endl;
}