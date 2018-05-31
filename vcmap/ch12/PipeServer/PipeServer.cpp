#include "stdafx.h"
#include "../../shared/mcd.h"
#include <windows.h>
#include <conio.h>

int _tmain()
{
	printf("hello，我是Pipe服务端...\r\n");

	//获取标准输入输出句柄
	HANDLE hStdIn = ::GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD dwRead = 0;

	//从标准输入中读取参数
	int args[2];
	ReadFile(hStdIn, args, sizeof(args), &dwRead, NULL);
	if(dwRead > 0)
	{
		//计算mcd
		int a = args[0];
		int b = args[1];
		int c = mcd(a, b);
		DWORD dwWrite = 0;
		WriteFile(hStdOut, &c, sizeof(c), &dwWrite, NULL);
	}

	return 0;
}