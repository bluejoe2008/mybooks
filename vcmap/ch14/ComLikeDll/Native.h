#pragma once
#include <iostream>
#include "IPhone.h"

#define MOBILE_PHONE_PART	0
#define MP3_PLAYER_PART	1

using namespace std;

class _MobilePhone : public IMobilePhone
{
private:
	void dial(string number);
	void talk();
	void hangup();
};

class _Mp3Player : public IMp3Player
{
private:
	void play(string movie);
};

class NativeMobilePhone : public IUnknown
{
public:
	NativeMobilePhone();
	~NativeMobilePhone();
	void AddRef();
	void Release();
	bool QueryInterface(int interfaceType, void ** ppObject);

private:
	int _ref;
	_MobilePhone _phone;
	_Mp3Player _mp3;
};
