#pragma once
#include "CSockEventServerDlg.h"

// CMcdServerSocket ÃüÁîÄ¿±ê

class CMcdServerSocket : public CSocket
{
public:
	CMcdServerDlg * m_pDialog;
	CMcdServerSocket(CMcdServerDlg * pDialog);
	virtual ~CMcdServerSocket();
	virtual void OnReceive(int nErrorCode);
};


