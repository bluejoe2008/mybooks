#pragma once

// CHttpClientSocket ÃüÁîÄ¿±ê

class CHttpClientDlg;

class CHttpClientSocket : public CSocket
{
private:
	CHttpClientDlg * m_pDlg;
	CString m_Response;
public:
	CHttpClientSocket(CHttpClientDlg * pDlg);
	virtual ~CHttpClientSocket();
	virtual void OnReceive(int nErrorCode);
	void Request(CString sHost, UINT nPort, CString sPath);
};


