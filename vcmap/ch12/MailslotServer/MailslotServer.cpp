#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello，我是Mailslot服务端...\r\n");

	//创建邮槽
	HANDLE hMailslot;
	hMailslot = CreateMailslot(_T("\\\\.\\mailslot\\MyMailslot"), 0, 
		MAILSLOT_WAIT_FOREVER, NULL);
	if(INVALID_HANDLE_VALUE == hMailslot)
	{
		printf("创建邮槽失败！\r\n");
		return -1;
	}

	printf("按任意键读取客户端写入邮槽的参数...\r\n");
	_getch();

	int args[2];
	DWORD dwRead;
	ReadFile(hMailslot, args, sizeof(args), &dwRead, NULL);

	//从客户端读取参数
	int a, b, c;
	int * pIntBuf = args;
	a = *(pIntBuf);
	pIntBuf++;
	b = *(pIntBuf);

	printf("读取到参数(%d, %d)\r\n", a, b);

	//输出计算结果
	c = mcd(a, b);
	printf("计算出mcd=%d\r\n", c);

	CloseHandle(hMailslot);
	return 0;
}