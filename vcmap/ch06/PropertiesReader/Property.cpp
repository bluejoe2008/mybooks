#include "StdAfx.h"
#include "Property.h"

CProperty::CProperty(CString value)
{
	_value = value;
}

CString CProperty::getString(void)
{
	return _value;
}

int CProperty::getInteger(void)
{
	return atoi(LPCTSTR(_value));
}

bool CProperty::getBoolean(void)
{
	return CString("true").CompareNoCase(_value) == 0;
}
