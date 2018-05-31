#include "stdafx.h"
#include "../../shared/mcd.h"

#include <winsock2.h>
#include <stdio.h>
#include <locale.h>
#pragma comment( lib, "Ws2_32.lib" )

int _tmain()
{
	setlocale(LC_ALL, "chs");

	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != NO_ERROR) 
	{
		_tprintf(_T("WSAStartup()调用失败！\r\n"));
		return -1;
	}

	//创建一个socket
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET)
	{
		_tprintf(_T("创建socket失败！\r\n"));
		WSACleanup();
		return -1;
	}

	//设置参数
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(0x1224);

	if (bind( ListenSocket, 
		(SOCKADDR*) &service, 
		sizeof(service)) == SOCKET_ERROR)
	{
		_tprintf(_T("绑定地址时报错！\r\n"));
		closesocket(ListenSocket);
		WSACleanup();
		return -1;
	}

	//开始监听
	if (listen( ListenSocket, 1 ) == SOCKET_ERROR)
	{
		_tprintf(_T("监听时报错！\r\n"));
		closesocket(ListenSocket);
		WSACleanup();
		return -1;
	}

	_tprintf(_T("正在监听...\r\n"));
	SOCKET AcceptSocket;

	AcceptSocket = accept( ListenSocket, NULL, NULL );
	if (AcceptSocket == INVALID_SOCKET)
	{
		_tprintf(_T("接受新连接时报错！\r\n"));
		closesocket(ListenSocket);
		WSACleanup();
		return -1;
	}
	else 
	{
		_tprintf(_T("已有客户端连接接入！\r\n"));
		int params[2];
		int bytes;
		bytes = recv(AcceptSocket, (char *)params, sizeof(params), 0);
		_tprintf(_T("成功接收%d个字节，内容：%d, %d\r\n"), bytes, params[0], params[1]);
		int m = mcd(params[0], params[1]);
		bytes = send(AcceptSocket, (const char *)&m, sizeof(m), 0);
		_tprintf(_T("成功回复%d个字节，内容：%d\r\n"), bytes, m);
	}

	closesocket(ListenSocket);
	_tprintf(_T("关闭客户连接！\r\n"));

	WSACleanup();
	return 0;
}