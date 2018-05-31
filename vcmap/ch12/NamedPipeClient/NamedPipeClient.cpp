#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello，我是NamedPipe客户端...\r\n");

	//WaitNamedPipe相当于Connect
	if(!WaitNamedPipe(_T("\\\\.\\pipe\\MyPipe"), NMPWAIT_WAIT_FOREVER))
	{
		printf("找不到MyPipe！是不是没有启动服务器端？\r\n");
		return -1;
	}

	HANDLE hPipe = CreateFile(_T("\\\\.\\pipe\\MyPipe"), GENERIC_READ | GENERIC_WRITE, 
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(INVALID_HANDLE_VALUE==hPipe)
	{
		printf("打开命名管道失败！\r\n");
		return -1;
	}

	DWORD dwWrite = 0;
	int args[] = {121, 33};
	WriteFile(hPipe, args, sizeof(args), &dwWrite, NULL);
	printf("参数(%d, %d)已写入，按任意键读取结果...\r\n", args[0], args[1]);
	_getch();

	int c;
	DWORD dwRead;
	ReadFile(hPipe, &c, sizeof(c), &dwRead, NULL);
	printf("读取到服务端写入命名管道的结果: %d\r\n", c);

	return 0;
}