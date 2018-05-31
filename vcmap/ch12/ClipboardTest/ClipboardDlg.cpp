// ClipboardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Clipboard.h"
#include "ClipboardDlg.h"

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


// CClipboardDlg 对话框




CClipboardDlg::CClipboardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClipboardDlg::IDD, pParent)
	, m_Text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClipboardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Text);
}

BEGIN_MESSAGE_MAP(CClipboardDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_COPY_DATA, &CClipboardDlg::OnBnClickedCopyData)
	ON_BN_CLICKED(IDC_PASTE_DATA, &CClipboardDlg::OnBnClickedPasteData)
END_MESSAGE_MAP()


// CClipboardDlg 消息处理程序

BOOL CClipboardDlg::OnInitDialog()
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

void CClipboardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClipboardDlg::OnPaint()
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
HCURSOR CClipboardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CClipboardDlg::OnBnClickedCopyData()
{
	//获取文本内容
	UpdateData(TRUE);
	if(OpenClipboard())
	{
		//分配全局内存块
		int size = m_Text.GetLength() * sizeof(TCHAR);
		HANDLE hMem = GlobalAlloc(GMEM_MOVEABLE, size + 1 * sizeof(TCHAR));
		TCHAR * buffer = (TCHAR *)GlobalLock(hMem);
		memset(buffer, 0, size + 1 * sizeof(TCHAR));
		memcpy(buffer, (LPCTSTR)m_Text, size);
		GlobalUnlock(hMem);

		//先清空剪贴板
		EmptyClipboard();
		//设置剪贴板的内容
#ifdef UNICODE
		SetClipboardData(CF_UNICODETEXT, hMem);
#else
		SetClipboardData(CF_TEXT, hMem);
#endif
		CloseClipboard();
	}
}

void CClipboardDlg::OnBnClickedPasteData()
{
	if(OpenClipboard())
	{
		//ANSI编码
		if(IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hMem = GetClipboardData(CF_TEXT);
			char * buffer = (char *)GlobalLock(hMem);
			GlobalUnlock(hMem);
			m_Text = buffer;
		}

		//UNICODE编码
		if(IsClipboardFormatAvailable(CF_UNICODETEXT))
		{
			HANDLE hMem = GetClipboardData(CF_UNICODETEXT);
			wchar_t * buffer = (wchar_t *)GlobalLock(hMem);
			GlobalUnlock(hMem);
			m_Text = buffer;
		}

		CloseClipboard();
		UpdateData(FALSE);
	}
}