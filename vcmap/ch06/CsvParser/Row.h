#pragma once

class CRow
{
private:
	CStringArray * _row;
public:
	CRow(CStringArray * row);
	int getColumnCount(void);
	CString getColumn(int i);
};
