#include "stdafx.h"
#include "Native.h"

NativeMobilePhone::NativeMobilePhone()
{
	cout << "ding...欢迎使用山寨机！" << endl;
}

NativeMobilePhone::~NativeMobilePhone()
{
	cout << "再见！dang..." << endl;
}

void NativeMobilePhone::dial(string number)
{
	cout << number << endl;
	cout << "dudu..." << endl;
	cout << "电话已拨通..." << endl;
}

void NativeMobilePhone::talk()
{
	cout << "blablabla~~~~" << endl;
	cout << "@#$%^&*()!~~~~" << endl;
	cout << "blablabla~~~~" << endl;
}

void NativeMobilePhone::hangup()
{
	cout << "已正常挂断！" << endl;
	cout << "通话时间：xx分xx秒" << endl;
}

void NativeMobilePhone::play(string movie)
{
	cout << "正在播放《" << movie << "》..." << endl;
}
