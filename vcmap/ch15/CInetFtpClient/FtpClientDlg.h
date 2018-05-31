// FtpClientDlg.h : 头文件
//

#include "FtpClient.h"
#pragma once


// CFtpClientDlg 对话框
class CFtpClientDlg : public CDialog
{
// 构造
public:
	CFtpClientDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CFtpClientDlg();

// 对话框数据
	enum { IDD = IDD_HTTP_DIALOG };

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
	CString m_sUrl;
	CString m_sResponse;

	void ShowResponse(CString msg);
	CString m_sStatus;
	void ShowStatus(CString msg);
	afx_msg void OnBnClickedButton1();
};
