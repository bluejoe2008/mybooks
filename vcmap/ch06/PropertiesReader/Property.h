#pragma once

class CProperty
{
private:
	CString _value;
public:
	CProperty(CString value);
	CString getString(void);
	int getInteger(void);
	bool getBoolean(void);
};
