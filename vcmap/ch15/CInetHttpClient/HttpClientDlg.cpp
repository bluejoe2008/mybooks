// HttpSocketDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpClient.h"
#include "HttpClientDlg.h"

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


// CHttpClientDlg 对话框




CHttpClientDlg::CHttpClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHttpClientDlg::IDD, pParent)
	, m_sUrl(_T("http://vcer.net"))
	, m_sResponse(_T(""))
	, m_sStatus(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHttpClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sUrl);
	DDX_Text(pDX, IDC_EDIT2, m_sResponse);
	DDX_Text(pDX, IDC_STATUS, m_sStatus);
}

BEGIN_MESSAGE_MAP(CHttpClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CHttpClientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CHttpClientDlg 消息处理程序

BOOL CHttpClientDlg::OnInitDialog()
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

void CHttpClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHttpClientDlg::OnPaint()
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
HCURSOR CHttpClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CHttpClientDlg::~CHttpClientDlg()
{
}


void CHttpClientDlg::ShowResponse(CString msg)
{
	this->m_sResponse = msg;
	UpdateData(FALSE);
}

void CHttpClientDlg::ShowStatus(CString msg)
{
	this->m_sStatus = msg;
	UpdateData(FALSE);
}

void CHttpClientDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString sHost;
	INTERNET_PORT nPort;
	CString sPath;

	DWORD serviceType;
	//解析URL串
	if(AfxParseURL(m_sUrl, serviceType, sHost, sPath, nPort)
		&& serviceType == AFX_INET_SERVICE_HTTP)
	{
		//session
		CInternetSession session;
		//connection
		CHttpConnection * pConnection = session.GetHttpConnection(sHost, nPort);
		if(pConnection)
		{
			CString sObjectName;
			//file
			CHttpFile * pFile = pConnection->OpenRequest("GET", sObjectName);
			pFile->SendRequest();
			DWORD code;
			pFile->QueryInfoStatusCode(code);
			if(code == HTTP_STATUS_OK)
			{
				//读取文件
				CString body;
				char block[1024];
				DWORD read;
				while(true)
				{
					read = pFile->Read(block, 1024);
					block[read - 1] = 0;
					body += block;

					if(read < 1024)
						break;
				}
				//读取完毕，显示之
				ShowResponse(body);
			}
		}
	}
}