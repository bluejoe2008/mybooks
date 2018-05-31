#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello，我是NamedPipe服务端...\r\n");

	//创建好管道MyPipe
	HANDLE hPipe = CreateNamedPipe(_T("\\\\.\\pipe\\MyPipe"), 
		PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 
		0, 1, 1024, 1024, 0, NULL);
	if(INVALID_HANDLE_VALUE == hPipe)
	{
		printf("创建命名管道失败！\r\n");
		return -1;
	}

	HANDLE hEvent;
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	OVERLAPPED ovlap;
	ZeroMemory(&ovlap, sizeof(OVERLAPPED));
	ovlap.hEvent = hEvent;

	//ConnectNamedPipe相当于Accept
	ConnectNamedPipe(hPipe, &ovlap);
	//一直等到有客户端的连接
	WaitForSingleObject(hEvent, INFINITE);
	CloseHandle(hEvent);

	int args[2];
	DWORD dwRead, dwWrite;

	//读取
	ReadFile(hPipe, args, 100, &dwRead, NULL);
	int a = args[0];
	int b = args[1];
	printf("读取到参数(%d, %d)\r\n", a, b);

	int c = mcd(a, b);

	//写入
	WriteFile(hPipe, &c, sizeof(c), &dwWrite, NULL);
	printf("计算出mcd=%d，结果已写入命名管道\r\n", c);

	printf("按任意键关闭程序...\r\n");
	_getch();

	return 0;
}