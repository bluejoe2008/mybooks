#include "stdafx.h"

//写入文本
void WriteString(HKEY key, CStringW valueName, CStringW value)
{
	RegSetValueEx(key, valueName, 0, REG_SZ, (LPBYTE)(LPCTSTR)value, (value.GetLength() + 1) * sizeof(TCHAR));
}

//写入bool
void WriteBoolean(HKEY key, CStringW valueName, bool value)
{
	WriteString(key, valueName, value ? _T("true") : _T("false"));
}

//写入DWORD
void WriteNumber(HKEY key, CStringW valueName, DWORD value)
{
	RegSetValueEx(key, valueName, 0, REG_DWORD, (LPBYTE)&value, sizeof(value));
}

void WriteProps()
{
	HKEY key;
	//创建键
	RegCreateKey(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"), &key);
	
	WriteString(key, _T("hotelName"), _T("尚儒客栈"));
	WriteString(key, _T("boss"), _T("吕轻侯"));
	WriteNumber(key, _T("maxClients"), 5);
	WriteBoolean(key, _T("isOpen"), false);
	RegCloseKey(key);
}


int main()
{
	WriteProps();

	return 0;
}