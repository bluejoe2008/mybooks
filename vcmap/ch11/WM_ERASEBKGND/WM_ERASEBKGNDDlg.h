// WM_ERASEBKGNDDlg.h : 头文件
//

#include <atlimage.h>
#pragma once


// CWM_ERASEBKGNDDlg 对话框
class CWM_ERASEBKGNDDlg : public CDialog
{
// 构造
public:
	CWM_ERASEBKGNDDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_WM_ERASEBKGND_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CImage m_Image;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
