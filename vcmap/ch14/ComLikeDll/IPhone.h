#pragma once
#include <string>
using namespace std;

class IUnknown
{
public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual bool QueryInterface(int interfaceType, void ** ppObject) = 0;
};

class IMobilePhone
{
public:
	virtual void dial(string number) = 0;
	virtual void talk() = 0;
	virtual void hangup() = 0;
};

class IMp3Player
{
public:
	virtual void play(string movie) = 0;
};
