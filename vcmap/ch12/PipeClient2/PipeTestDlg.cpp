// PipeTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PipeTest.h"
#include "PipeTestDlg.h"

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


// CPipeTestDlg 对话框




CPipeTestDlg::CPipeTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CPipeTestDlg::IDD, pParent)
, m_radius(0)
, m_cir(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPipeTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_radius);
	DDX_Text(pDX, IDC_EDIT2, m_cir);
}

BEGIN_MESSAGE_MAP(CPipeTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RUN_IT, &CPipeTestDlg::OnBnClickedRunIt)
END_MESSAGE_MAP()


// CPipeTestDlg 消息处理程序

BOOL CPipeTestDlg::OnInitDialog()
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

void CPipeTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPipeTestDlg::OnPaint()
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
HCURSOR CPipeTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPipeTestDlg::OnBnClickedRunIt()
{
	UpdateData(TRUE);

	HANDLE hChildStdInRead, hChildStdInWrite;
	HANDLE hChildStdOutRead, hChildStdOutWrite;

	//安全属性
	SECURITY_ATTRIBUTES sa; 

	sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
	sa.bInheritHandle = TRUE; //子进程可以继承父进程创建管道的读写句柄
	sa.lpSecurityDescriptor = NULL; 

	//创建标准输入管道
	if(!CreatePipe(&hChildStdInRead, &hChildStdInWrite, &sa, 0))
	{
		MessageBox(_T("创建标准输入管道失败！"));
		return;
	}

	//创建标准输出管道
	if(!CreatePipe(&hChildStdOutRead, &hChildStdOutWrite, &sa, 0))
	{
		MessageBox(_T("创建标准输出管道失败！"));
		return;
	}

	//线程属性
	PROCESS_INFORMATION pi; 
	STARTUPINFO si = {sizeof(si)};
	si.wShowWindow = SW_HIDE;
	si.hStdInput = hChildStdInRead;
	si.hStdOutput = hChildStdOutWrite;
	si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES; //使用显示窗口和标准句柄的标志

	TCHAR cCommandLine[_MAX_PATH] = _T("PipeServer.exe");

	// 启动PipeServer.exe
	if (CreateProcess(NULL, cCommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);

		DWORD count;
		count = 0;
		//发送半径值
		WriteFile(hChildStdInWrite, &m_radius, sizeof(m_radius), &count, NULL);

		count = 0;
		//读取圆周值
		ReadFile(hChildStdOutRead, &m_cir, sizeof(m_cir), &count, NULL);

		UpdateData(FALSE);
	}
}
