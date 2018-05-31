// McdClientSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "McdClient.h"
#include "McdClientDlg.h"
#include "McdClientSocket.h"


// CMcdClientSocket

CMcdClientSocket::CMcdClientSocket(CMcdClientDlg * pDialog)
{
	m_pDialog = pDialog;
}

CMcdClientSocket::~CMcdClientSocket()
{
}


// CMcdClientSocket 成员函数

void CMcdClientSocket::OnReceive(int nErrorCode)
{
	int m;
	int bytes;

	bytes = Receive((char *)&m, sizeof(m));
	CString msg;
	msg.Format(_T("mcd(%d, %d) = %d"), m_pDialog->_a, m_pDialog->_b, m);

	m_pDialog->MessageBox(msg);
}

int CMcdClientSocket::SendNumbers(int a, int b)
{
	int m[2] = {a, b};
	return Send((const char *)m, sizeof(m));
}
