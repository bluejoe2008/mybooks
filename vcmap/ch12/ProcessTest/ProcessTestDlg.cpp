// ProcessTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ProcessTest.h"
#include "ProcessTestDlg.h"

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


// CProcessTestDlg 对话框




CProcessTestDlg::CProcessTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CProcessTestDlg::IDD, pParent)
, m_FileContent(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcessTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FILE_CONTENT, m_FileContent);
}

BEGIN_MESSAGE_MAP(CProcessTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_OPEN_FILE, &CProcessTestDlg::OnBnClickedOpenFile)
	ON_BN_CLICKED(ID_EDIT_FILE, &CProcessTestDlg::OnBnClickedEditFile)
	ON_STN_CLICKED(IDC_FILE_CONTENT, &CProcessTestDlg::OnStnClickedFileContent)
END_MESSAGE_MAP()


// CProcessTestDlg 消息处理程序

BOOL CProcessTestDlg::OnInitDialog()
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

void CProcessTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProcessTestDlg::OnPaint()
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
HCURSOR CProcessTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CProcessTestDlg::OnBnClickedOpenFile()
{
	CFileDialog dlg(TRUE);
	dlg.DoModal();

	m_FilePath = dlg.GetPathName();
	LoadFileContent();
}

int CProcessTestDlg::LoadFileContent(void)
{
	//打开指定文件
	CFile file(m_FilePath, CFile::modeRead);

	m_FileContent = "";
	char bytes[1024];
	while(true)
	{
		//每1024个字节一读
		memset(bytes, 0, sizeof(bytes));
		int read = file.Read(bytes, sizeof(bytes));
		m_FileContent += bytes;

		//读到结尾了
		if(read < sizeof(bytes))
			break;
	}

	UpdateData(FALSE);
	return 0;
}

void CProcessTestDlg::OnBnClickedEditFile()
{
	PROCESS_INFORMATION pi; 
	STARTUPINFO si = {sizeof(si)};
	TCHAR cCommandLine[_MAX_PATH];

	// 记事本程序的命令行
	_stprintf(cCommandLine, _T("notepad.exe \"%s\""), m_FilePath);

	// 启动记事本
	if (CreateProcess(NULL, cCommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{ 
		// 等待子进程的退出 
		WaitForSingleObject(pi.hProcess, INFINITE); 
		// 关闭子进程句柄 
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);

		//重新加载文件内容
		LoadFileContent();
	}
}

void CProcessTestDlg::OnStnClickedFileContent()
{
	// TODO: 在此添加控件通知处理程序代码
}
