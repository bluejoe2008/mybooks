#pragma once
#include "property.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class CProperties
{
private:
	CMapStringToPtr _map; 
public:
	CProperty * getProperty(CString name);
	~CProperties(void);
	int loadFrom(ifstream & in);
};
