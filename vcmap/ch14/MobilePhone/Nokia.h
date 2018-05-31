#pragma once
#include <iostream>
#include "IPhone.h"
using namespace std;

class NokiaMobilePhone : public IMobilePhone
{
public:
	NokiaMobilePhone();
	~NokiaMobilePhone();
private:
	void dial(string number);
	void talk();
	void hangup();
};
