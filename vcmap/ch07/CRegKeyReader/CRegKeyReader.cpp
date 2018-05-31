#include "stdafx.h"
#include "atlbase.h"

//读取文本值
bool ReadString(CRegKey & key, CStringW valueName, CStringW & value)
{
	TCHAR s[_MAX_PATH];
	DWORD len = _MAX_PATH;
	if(key.QueryStringValue(valueName, s, &len) == ERROR_SUCCESS)
	{
		value = s;
		return true;
	}

	return false;
}

//读取bool值
bool ReadBoolean(CRegKey & key, CStringW valueName, bool & value)
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
bool ReadNumber(CRegKey & key, CStringW valueName, DWORD & value)
{
	DWORD s;
	if(key.QueryDWORDValue(valueName, s) == ERROR_SUCCESS)
	{
		value = s;
		return true;
	}

	return false;
}

void ReadProps()
{
	CRegKey key;
	key.Open(HKEY_LOCAL_MACHINE, _T("Software\\bluejoe\\hotel"));

	CStringW hotelName, boss;
	DWORD maxClients;
	bool isOpen;

	ReadString(key, _T("hotelName"), hotelName);
	ReadString(key, _T("boss"), boss);
	ReadNumber(key, _T("maxClients"), maxClients);
	ReadBoolean(key, _T("isOpen"), isOpen);

	_tprintf(_T("酒店: %s\r\n老板: %s\r\n最大顾客数: %d\r\n状态: %s\r\n"), hotelName, boss, maxClients, isOpen ? _T("开张") : _T("关闭")); 
}

int main()
{
	setlocale(LC_ALL, "chs");
	ReadProps();

	return 0;
}