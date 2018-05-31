#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

#define BUF_SIZE 1024

int _tmain()
{
	printf("hello，我是FileMapping服务端...\r\n");

	HANDLE hMapFile;
	LPVOID pBuf;

	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,		// use paging file
		NULL,						// default security 
		PAGE_READWRITE,				// read/write access
		0,							// max. object size 
		BUF_SIZE,					// buffer size  
		_T("MyFileMapping"));		// name of mapping object

	if (hMapFile == NULL) 
	{ 
		printf("创建文件映射失败！\r\n");
		return -1;
	}

	pBuf = MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,                   
		0,                   
		BUF_SIZE);           

	if (pBuf == NULL) 
	{ 
		printf("创建文件映射失败！\r\n");
		return 2;
	}

	printf("按任意键读取客户端写入文件映射的参数...\r\n");
	_getch();

	//从客户端读取参数
	int a, b, c;
	int * pIntBuf = (int *)pBuf;
	a = *(pIntBuf);
	pIntBuf++;
	b = *(pIntBuf);
	c = mcd(a, b);

	printf("读取到参数(%d, %d)\r\n", a, b);

	//写回计算结果
	pIntBuf++;
	*pIntBuf = c;

	printf("计算出mcd=%d，结果已写入文件映射\r\n", c);

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);

	return 0;
}