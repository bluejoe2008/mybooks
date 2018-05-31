// FlashPlayerDlg.h : 头文件
//

#pragma once
#include "shockwaveflash1.h"


// CFlashPlayerDlg 对话框
class CFlashPlayerDlg : public CDialog
{
// 构造
public:
	CFlashPlayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FLASHPLAYER_DIALOG };

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
	CShockwaveflash1 m_FlashCtrl;
	CString m_MoviePath;
	afx_msg void OnBnClickedButton2();
};
