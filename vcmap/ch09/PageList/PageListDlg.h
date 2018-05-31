// PageListDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CPageListDlg 对话框
class CPageListDlg : public CDialog
{
// 构造
public:
	CPageListDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PAGELIST_DIALOG };

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
	CStatic m_ToolBarContainer;
	CStatic m_PageContainer;

	CToolBar m_ToolBar;
	CDialog * m_ActivePage;
	CDialog * m_Page1;
	CDialog * m_Page2;
	afx_msg void OnDestroy();
	afx_msg void OnXPage1();
	afx_msg void OnXPage2();
	void ActivePage(CDialog * pDialog);
};
