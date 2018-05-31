// CSockEventServerDlg.h : 头文件
//

#pragma once
#include "McdListenSocket.h"

// CMcdServerDlg 对话框
class CMcdServerDlg : public CDialog
{
// 构造
public:
	CMcdServerDlg(CWnd* pParent = NULL);	// 标准构造函数
	CMcdListenSocket * m_pListenSocket;

// 对话框数据
	enum { IDD = IDD_CSOCKEVENTSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	~CMcdServerDlg(void);
};
