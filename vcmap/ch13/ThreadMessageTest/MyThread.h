#pragma once

#include "MyDialog.h"

// CMyThread

class CMyThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyThread)

protected:
	CMyThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyThread();

public:
	CMyDialog m_dialog;
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


