#pragma once
#include <iostream>
#include "IPhone.h"
using namespace std;

class NativeMobilePhone : public IMobilePhone, public IMp3Player
{
public:
	NativeMobilePhone();
	~NativeMobilePhone();
private:
	void dial(string number);
	void talk();
	void hangup();
	void play(string movie);
};
