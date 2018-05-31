// CommDlgTestDlg.h : 头文件
//

#pragma once


// CCommDlgTestDlg 对话框
class CCommDlgTestDlg : public CDialog
{
// 构造
public:
	CCommDlgTestDlg(CWnd* pParent = NULL);	// 标准构造函数
	CFindReplaceDialog * _pFindReplaceDlg;

// 对话框数据
	enum { IDD = IDD_COMMDLGTEST_DIALOG };

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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnDestroy();
//	afx_msg void OnNcDestroy();
};
