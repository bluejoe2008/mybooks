#include "stdafx.h"
#include <windows.h>

int _tmain()
{
	printf("hello，我是Pipe客户端...\r\n");

	HANDLE hChildStdInRead, hChildStdInWrite;
	HANDLE hChildStdOutRead, hChildStdOutWrite;

	//安全属性
	SECURITY_ATTRIBUTES sa; 

	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
	sa.bInheritHandle = TRUE; //子进程可以继承父进程创建管道的读写句柄
	sa.lpSecurityDescriptor = NULL; 

	//创建标准输入管道
	if(!CreatePipe(&hChildStdInRead, &hChildStdInWrite, &sa, 0))
	{
		printf("创建标准输入管道失败！");
		return -1;
	}

	//创建标准输出管道
	if(!CreatePipe(&hChildStdOutRead, &hChildStdOutWrite, &sa, 0))
	{
		printf("创建标准输出管道失败！");
		return -1;
	}

	//进程属性
	PROCESS_INFORMATION pi; 
	STARTUPINFO si = {sizeof(si)};
	si.wShowWindow = SW_HIDE;
	si.hStdInput = hChildStdInRead;
	si.hStdOutput = hChildStdOutWrite;
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES; //使用显示窗口和标准句柄的标志

	TCHAR cCommandLine[_MAX_PATH] = _T("PipeServer.exe");

	// 启动PipeServer.exe
	if (CreateProcess(NULL, cCommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		DWORD dwWrite = 0;
		int args[] = {121, 33};
		//发送参数值
		WriteFile(hChildStdInWrite, args, sizeof(args), &dwWrite, NULL);
		printf("写入管道的参数: (%d, %d)\r\n", args[0], args[1]);

		DWORD dwRead = 0;
		int c;
		ReadFile(hChildStdOutRead, &c, sizeof(c), &dwRead, NULL);
		printf("读取到服务端写入管道的结果: mcd=%d\r\n", c);
	}

	return 0;
}