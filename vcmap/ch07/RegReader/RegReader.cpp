#include "stdafx.h"

//读取文本值
bool ReadString(HKEY key, CStringW valueName, CStringW & value)
{
	DWORD type;
	BYTE s[_MAX_PATH];
	DWORD len = _MAX_PATH;
	if(RegQueryValueEx(key, valueName, 0, &type, s, &len) == ERROR_SUCCESS)
	{
		value = (TCHAR *)s;
		return true;
	}

	return false;
}

//读取bool值
bool ReadBoolean(HKEY key, CStringW valueName, bool & value)
{
	CStringW s;
	//先读取文本值
	if(ReadString(key, valueName, s))
	{
		//判断其是否为true
		value = (CStringW("true").CompareNoCase(s) == 0);
		return true;
	}

	return false;
}

//读取DWORD值
bool ReadNumber(HKEY key, CStringW valueName, DWORD & value)
{
	DWORD type;
	DWORD s;
	DWORD len = sizeof(DWORD);
	if(RegQueryValueEx(key, valueName, 0, &type, (LPBYTE)&s, &len) == ERROR_SUCCESS)
	{
		value = s;
		return true;
	}

	return false;
}

void ReadProps()
{
	HKEY key;
	//打开键
	RegOpenKey(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"), &key);
	
	CStringW hotelName, boss;
	DWORD maxClients;
	bool isOpen;

	ReadString(key, _T("hotelName"), hotelName);
	ReadString(key, _T("boss"), boss);
	ReadNumber(key, _T("maxClients"), maxClients);
	ReadBoolean(key, _T("isOpen"), isOpen);
	RegCloseKey(key);

	_tprintf(_T("酒店: %s\r\n老板: %s\r\n最大顾客数: %d\r\n状态: %s\r\n"), hotelName, boss, maxClients, isOpen ? _T("开张") : _T("关闭")); 
}

int main()
{
	setlocale(LC_ALL, "chs");
	ReadProps();

	return 0;
}
