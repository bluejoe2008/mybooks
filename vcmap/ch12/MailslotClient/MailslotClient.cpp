#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello，我是Mailslot客户端...\r\n");

	HANDLE hMailslot;
	hMailslot = CreateFile(_T("\\\\.\\mailslot\\MyMailslot"), GENERIC_WRITE | GENERIC_READ, 
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(INVALID_HANDLE_VALUE == hMailslot)
	{
		printf("找不到MyMailslot！是不是没有启动服务器端？\r\n");
		return -1;
	}

	//写入参数
	DWORD dwWrite;
	int args[] = {12, 18};
	WriteFile(hMailslot, args, sizeof(args), &dwWrite, NULL);
	printf("参数(%d, %d)已写入邮槽...\r\n", args[0], args[1]);

	CloseHandle(hMailslot);
	return 0;
}