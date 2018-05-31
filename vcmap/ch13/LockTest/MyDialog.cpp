// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "UIThreadTest.h"
#include "MyDialog.h"
#include "MyThread.h"


// CCopyFileDialog 对话框

IMPLEMENT_DYNAMIC(CCopyFileDialog, CDialog)

CCopyFileDialog::CCopyFileDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CCopyFileDialog::IDD, pParent)
{
}

CCopyFileDialog::~CCopyFileDialog()
{
}

void CCopyFileDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl);
	DDX_Control(pDX, IDC_PROGREASS_TEXT, m_ProgressText);
}


BEGIN_MESSAGE_MAP(CCopyFileDialog, CDialog)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CCopyFileDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

void CCopyFileDialog::OnTimer(UINT_PTR nIDEvent)
{
	//显示进度条
	m_Ticks++;
	m_ProgressCtrl.SetPos(m_Ticks);

	CString s;
	s.Format(_T("%d%%"), m_Ticks);
	//显示进度百分比
	m_ProgressText.SetWindowText(s);

	//拷贝完毕
	if(m_Ticks == 100)
	{
		((CCopyFileThread *)AfxGetThread())->m_FileCopiedEvent.SetEvent();
		OnCancel();
	}
}

BOOL CCopyFileDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Ticks = 0;
	SetTimer(1, 100, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CCopyFileDialog::OnBnClickedCancel()
{
	((CCopyFileThread *)AfxGetThread())->m_FileCancelledEvent.SetEvent();
	OnCancel();
}
