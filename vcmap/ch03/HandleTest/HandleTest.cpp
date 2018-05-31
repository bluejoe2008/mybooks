#include "stdafx.h"

int main()
{
	HANDLE hFile1 = CreateFile( _T("test1.out"),
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		0,
		NULL );

	HANDLE hFile2 = CreateFile( _T("test2.out"),
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		0,
		NULL );

	_tprintf(_T("HANDLE: %d\r\n"), hFile1);
	_tprintf(_T("HANDLE: %d\r\n"), hFile2);

	CloseHandle(hFile1);
	CloseHandle(hFile2);

	return 0;
}