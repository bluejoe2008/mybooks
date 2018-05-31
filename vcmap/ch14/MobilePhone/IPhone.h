#pragma once
#include <string>
using namespace std;

class IMobilePhone
{
public:
	virtual void dial(string number) = 0;
	virtual void talk() = 0;
	virtual void hangup() = 0;
	virtual ~IMobilePhone()	{}
};

class IMp3Player
{
public:
	virtual void play(string movie) = 0;
};