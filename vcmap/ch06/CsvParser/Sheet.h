#pragma once

#include <fstream>
#include "row.h"

using namespace std;

class CSheet
{
private:
	CTypedPtrArray<CPtrArray, CStringArray *> _rows;
public:
	CSheet(void);
	~CSheet(void);
	int loadFrom(ifstream & in);
	int getRowCount(void);
	CRow getRow(int i);
};
