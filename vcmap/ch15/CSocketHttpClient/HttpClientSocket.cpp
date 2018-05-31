// HttpClient.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpClient.h"
#include "HttpClient.h"
#include "HttpClientDlg.h"


// CHttpClientSocket

CHttpClientSocket::CHttpClientSocket(CHttpClientDlg * pDlg)
{
	m_pDlg = pDlg;
}

CHttpClientSocket::~CHttpClientSocket()
{
}


// CHttpClientSocket 成员函数

void CHttpClientSocket::OnReceive(int nErrorCode)
{
	//接收到了HTTP响应
	char buffer[1024] = {0};
	while(true)
	{
		//多次读取
		int read = this->CAsyncSocket::Receive(buffer, 1024);
		if(read <= 0)
			break;

		buffer[read - 1] = 0;
		m_Response += buffer;
	}

	//显示响应
	m_pDlg->ShowResponse(m_Response);

	CString msg;
	msg.Format(_T("成功接收%d字节！"), m_Response.GetLength());
	m_pDlg->ShowStatus(msg);
}

//发送url请求
void CHttpClientSocket::Request(CString sHost, UINT nPort, CString sPath)
{
	this->Connect(sHost, nPort);
	m_Response = "";

	CString request;
	request.Format(_T("GET %s HTTP/1.1\r\nhost:%s\r\n\r\n"), sPath, sHost);
	int send = this->Send((LPCTSTR)request, request.GetLength() * sizeof(TCHAR));
	if(send <= 0)
	{
		m_pDlg->ShowStatus(_T("无法打开网页！"));
	}
	else
	{
		CString msg;
		msg.Format(_T("成功发送%d字节！"), send);
		m_pDlg->ShowStatus(msg);
	}
}
