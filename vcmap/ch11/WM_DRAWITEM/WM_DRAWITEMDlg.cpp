// WM_DRAWITEMDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WM_DRAWITEM.h"
#include "WM_DRAWITEMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CWM_DRAWITEMDlg 对话框




CWM_DRAWITEMDlg::CWM_DRAWITEMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWM_DRAWITEMDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWM_DRAWITEMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWM_DRAWITEMDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CWM_DRAWITEMDlg 消息处理程序

BOOL CWM_DRAWITEMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWM_DRAWITEMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWM_DRAWITEMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWM_DRAWITEMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CWM_DRAWITEMDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if(nIDCtl == IDC_BUTTON1)
	{
		//绘制按钮外框

		UINT uStyle = DFCS_BUTTONPUSH;
		//是否按下去了？
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
			uStyle |= DFCS_PUSHED;

		CDC dc;
		dc.Attach(lpDrawItemStruct->hDC);
		dc.DrawFrameControl(&lpDrawItemStruct->rcItem, DFC_BUTTON, uStyle);

		//获取其文本
		CWnd * pCtrl = GetDlgItem(nIDCtl);
		CString sText;
		pCtrl->GetWindowText(sText);
		//输出笑脸
		if (lpDrawItemStruct->itemState & ODS_SELECTED)
		{
			sText += ":(";
		}
		else
		{
			sText += ":)";
		}


		//输出文字
		dc.TextOut(lpDrawItemStruct->rcItem.left + 20, lpDrawItemStruct->rcItem.top + 20, sText);

		//是否得到焦点
		if(lpDrawItemStruct->itemState & ODS_FOCUS)
		{
			//画虚框
			CRect rtFocus = lpDrawItemStruct->rcItem;
			rtFocus.DeflateRect(3, 3);
			dc.DrawFocusRect(&rtFocus);
		}

		return;
	}
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
