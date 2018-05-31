// ProcessTestDlg.h : 头文件
//

#pragma once


// CProcessTestDlg 对话框
class CProcessTestDlg : public CDialog
{
// 构造
public:
	CProcessTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PROCESSTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CString m_FilePath;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_FileContent;
	afx_msg void OnBnClickedOpenFile();
	int LoadFileContent(void);
	afx_msg void OnBnClickedEditFile();
	afx_msg void OnStnClickedFileContent();
};
