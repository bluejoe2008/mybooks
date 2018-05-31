#include "stdafx.h"
#include "Native.h"

void _MobilePhone::dial(string number)
{
	cout << number << endl;
	cout << "dudu..." << endl;
	cout << "电话已拨通..." << endl;
}

void _MobilePhone::talk()
{
	cout << "blablabla~~~~" << endl;
	cout << "@#$%^&*()!~~~~" << endl;
	cout << "blablabla~~~~" << endl;
}

void _MobilePhone::hangup()
{
	cout << "已正常挂断！" << endl;
	cout << "通话时间：xx分xx秒" << endl;
}

void _Mp3Player::play(string movie)
{
	cout << "正在播放《" << movie << "》..." << endl;
}	

bool NativeMobilePhone::QueryInterface(int interfaceType, void ** ppObject)
{
	if(interfaceType == MOBILE_PHONE_PART)
		*ppObject = &_phone;

	if(interfaceType == MP3_PLAYER_PART)
		*ppObject = &_mp3;

	return true;
}

NativeMobilePhone::NativeMobilePhone()
{
	cout << "ding...欢迎使用山寨机！" << endl;
	_ref = 1;
}

NativeMobilePhone::~NativeMobilePhone()
{
	cout << "再见！dang..." << endl;
}

void NativeMobilePhone::AddRef()
{
	_ref++;
}

void NativeMobilePhone::Release()
{
	_ref--;
	if(_ref == 0)
		delete this;
}
