#include "stdafx.h"
#include "atlbase.h"

//写入文本
void WriteString(CRegKey & key, CStringW valueName, CStringW value)
{
	key.SetStringValue(valueName, value);
}

//写入bool
void WriteBoolean(CRegKey & key, CStringW valueName, bool value)
{
	WriteString(key, valueName, value ? _T("true") : _T("false"));
}

//写入DWORD
void WriteNumber(CRegKey & key, CStringW valueName, DWORD value)
{
	key.SetDWORDValue(valueName, value);
}

void WriteProps()
{
	CRegKey key;
	key.Create(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"));
	
	WriteString(key, _T("hotelName"), _T("新龙门客栈"));
	WriteString(key, _T("boss"), _T("金香玉"));
	WriteNumber(key, _T("maxClients"), 5);
	WriteBoolean(key, _T("isOpen"), true);
}

int main()
{
	WriteProps();

	return 0;
}