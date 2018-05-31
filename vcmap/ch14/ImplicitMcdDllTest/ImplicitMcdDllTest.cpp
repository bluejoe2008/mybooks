#include "stdafx.h"
#include "windows.h"
#include "../../shared/mcd.h"

#pragma comment(lib, "../Debug/McdDll.lib")

int _tmain()
{
	_tprintf(_T("%d\r\n"), mcd(18, 24));

	return 0;
}