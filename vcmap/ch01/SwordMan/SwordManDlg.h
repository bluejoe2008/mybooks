// SwordManDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CSwordManDlg 对话框
class CSwordManDlg : public CDialog
{
// 构造
public:
	CSwordManDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SWORDMAN_DIALOG };

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
	CListCtrl m_ActorList;
public:
	CString m_Name;
public:
	int m_Age;
public:
	CString m_Words;

	CBitmap m_Faces;
	CImageList m_ImageList;
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
