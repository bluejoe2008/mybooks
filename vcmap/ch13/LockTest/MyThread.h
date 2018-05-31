#pragma once

#include "MyDialog.h"

// CCopyFileThread

class CCopyFileThread : public CWinThread
{
	DECLARE_DYNCREATE(CCopyFileThread)

protected:
	CCopyFileThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CCopyFileThread();

public:
	CCopyFileDialog m_dialog;
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CEvent m_FileCopiedEvent;
	CEvent m_FileCancelledEvent;

protected:
	DECLARE_MESSAGE_MAP()
};


