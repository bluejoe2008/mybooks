// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "UIThreadTest.h"
#include "MyDialog.h"


// CMyDialog 对话框

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgressCtrl);
	DDX_Control(pDX, IDC_PROGREASS_TEXT, m_ProgressText);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDCANCEL, &CMyDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

void CMyDialog::OnTimer(UINT_PTR nIDEvent)
{
	//显示进度条
	m_ProgressCtrl.SetPos(m_Ticks);

	CString s;
	s.Format(_T("%d%%"), m_Ticks);
	//显示进度百分比
	m_ProgressText.SetWindowText(s);

	if(m_Ticks == 100)
		m_Ticks = 0;

	m_Ticks++;
}

BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Ticks = 0;
	SetTimer(1, 100, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CMyDialog::OnDestroy()
{
	CDialog::OnDestroy();
	PostQuitMessage(0);
}

void CMyDialog::OnBnClickedCancel()
{
	DestroyWindow();
}
