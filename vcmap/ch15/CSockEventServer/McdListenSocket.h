#pragma once

class CMcdServerDlg;

// CMcdListenSocket ÃüÁîÄ¿±ê

class CMcdListenSocket : public CSocket
{
public:
	CPtrList m_Sockets;
	CMcdServerDlg * m_pDialog;

	CMcdListenSocket(CMcdServerDlg * pDialog);
	virtual ~CMcdListenSocket();
	virtual void OnAccept(int nErrorCode);
};


