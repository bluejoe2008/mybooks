// McdListenSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "CSockEventServer.h"
#include "McdServerSocket.h"
#include "McdListenSocket.h"


// CMcdListenSocket

CMcdListenSocket::CMcdListenSocket(CMcdServerDlg * pDialog)
{
	m_pDialog = pDialog;
}

CMcdListenSocket::~CMcdListenSocket()
{
	//依次析构m_Sockets中保存的CMcdServerSocket
	for(POSITION p = m_Sockets.GetHeadPosition(); p != m_Sockets.GetTailPosition(); m_Sockets.GetNext(p))
	{
		CMcdServerSocket *pServerSocket = (CMcdServerSocket *)m_Sockets.GetAt(p);
		delete pServerSocket;
	}

	m_Sockets.RemoveAll();
}


// CMcdListenSocket 成员函数

void CMcdListenSocket::OnAccept(int nErrorCode)
{
	//记录新创建的CMcdServerSocket，否则无法析构它们
	CMcdServerSocket *pServerSocket = new CMcdServerSocket(m_pDialog);
	m_Sockets.AddTail(pServerSocket);
	this->Accept(*pServerSocket);

	CString msg;
	CString address;
	UINT port;
	pServerSocket->GetSockNameEx(address, port);
	msg.Format(_T("接收到新的连接！该连接来自%s:%d"), address, port);
	m_pDialog->MessageBox(msg);
}
