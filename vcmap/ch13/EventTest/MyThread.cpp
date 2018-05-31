// MyThread.cpp : 实现文件
//

#include "stdafx.h"
#include "UIThreadTest.h"
#include "MyThread.h"
#include "MyDialog.h"


// CCopyFileThread

IMPLEMENT_DYNCREATE(CCopyFileThread, CWinThread)

CCopyFileThread::CCopyFileThread()
{
}

CCopyFileThread::~CCopyFileThread()
{
}

BOOL CCopyFileThread::InitInstance()
{
	m_pMainWnd = &m_dialog; 

	m_dialog.Create(IDD_DIALOG1);
	m_dialog.ShowWindow(SW_SHOW);
	return TRUE;
}

int CCopyFileThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CCopyFileThread, CWinThread)
END_MESSAGE_MAP()


// CCopyFileThread 消息处理程序
