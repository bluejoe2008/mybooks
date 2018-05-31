#include "stdafx.h"
#include <windows.h>
#include <conio.h>

#define BUF_SIZE 1024

int _tmain()
{
	printf("hello，我是FileMapping客户端...\r\n");

	HANDLE hMapFile;
	LPVOID pBuf;

	hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,		// read/write access
		FALSE,						// do not inherit the name
		_T("MyFileMapping"));		// name of mapping object 

	if (hMapFile == NULL) 
	{ 
		printf("打开文件映射失败！\r\n");
		return -1;
	} 

	pBuf = MapViewOfFile(hMapFile,	// handle to map object
		FILE_MAP_ALL_ACCESS,		// read/write permission
		0,                    
		0,                    
		BUF_SIZE);           

	if (pBuf == NULL) 
	{ 
		printf("打开文件映射失败！\r\n");
		return -1;
	}

	//写入两个参数
	int * pIntBuf = (int *)pBuf;
	int a = 12;
	int b = 18;
	*pIntBuf = a;
	pIntBuf++;
	*pIntBuf = b;

	printf("参数(%d, %d)已写入，按任意键读取结果...\r\n", a, b);
	_getch();

	pIntBuf++;
	int c = *pIntBuf;
	printf("读取到服务端写入文件映射的结果: %d\r\n", c);

	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);

	return 0;
}