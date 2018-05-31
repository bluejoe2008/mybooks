// McdServerSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "CSockEventServer.h"
#include "../../shared/mcd.h"
#include "McdServerSocket.h"


// CMcdServerSocket

CMcdServerSocket::CMcdServerSocket(CMcdServerDlg * pDialog)
{
	m_pDialog = pDialog;
}

CMcdServerSocket::~CMcdServerSocket()
{
}

void CMcdServerSocket::OnReceive(int nErrorCode)
{
	int params[2];
	int bytes;

	bytes = Receive((char *)params, sizeof(params));
	CString msg;
	msg.Format(_T("成功接收%d个字节，内容：%d, %d"), bytes, params[0], params[1]);

	m_pDialog->MessageBox(msg);
	int m = mcd(params[0], params[1]);
	Send((const char *)&m, sizeof(m));
}
