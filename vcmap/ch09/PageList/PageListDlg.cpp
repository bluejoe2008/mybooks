// PageListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PageList.h"
#include "Page1.h"
#include "Page2.h"
#include "PageListDlg.h"

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


// CPageListDlg 对话框




CPageListDlg::CPageListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageListDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ActivePage = NULL;
}

void CPageListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TOOLBAR_CONTAINER, m_ToolBarContainer);
	DDX_Control(pDX, IDC_PAGE_CONTAINER, m_PageContainer);
}

BEGIN_MESSAGE_MAP(CPageListDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_COMMAND(ID_X_PAGE1, &CPageListDlg::OnXPage1)
	ON_COMMAND(ID_X_PAGE2, &CPageListDlg::OnXPage2)
END_MESSAGE_MAP()


// CPageListDlg 消息处理程序

BOOL CPageListDlg::OnInitDialog()
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

	//创建工具栏
	m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
      | CBRS_GRIPPER | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_RIGHT | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	//加载工具栏
	m_ToolBar.LoadToolBar(IDR_TOOLBAR2);

	//设置属性
	m_ToolBar.GetToolBarCtrl().ModifyStyle(0, TBSTYLE_WRAPABLE);
	CRect rect;
	m_ToolBarContainer.GetWindowRect(&rect);
	ScreenToClient(rect);
	//摆放工具栏
	m_ToolBar.MoveWindow(&rect);

	//加载对话框
	m_Page1 = new CPage1();
	m_Page1->Create(CPage1::IDD);

	m_Page2 = new CPage2();
	m_Page2->Create(CPage2::IDD);

	//摆放对话框
	m_PageContainer.GetWindowRect(&rect);
	ScreenToClient(rect);

	m_Page1->MoveWindow(&rect);
	m_Page1->ShowWindow(SW_HIDE);

	m_Page2->MoveWindow(&rect);
	m_Page2->ShowWindow(SW_HIDE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPageListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPageListDlg::OnPaint()
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
HCURSOR CPageListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPageListDlg::OnDestroy()
{
	CDialog::OnDestroy();

	m_Page1->DestroyWindow();
	delete m_Page1;

	m_Page2->DestroyWindow();
	delete m_Page2;
}

void CPageListDlg::OnXPage1()
{
	ActivePage(m_Page1);
}

void CPageListDlg::OnXPage2()
{
	ActivePage(m_Page2);
}

void CPageListDlg::ActivePage(CDialog * pDialog)
{
	if(m_ActivePage != pDialog)
	{
		if(m_ActivePage != NULL)
		{
			//隐藏当前激活窗口
			m_ActivePage->ShowWindow(SW_HIDE);
		}

		pDialog->ShowWindow(SW_SHOW);
		m_ActivePage = pDialog;
	}
}
