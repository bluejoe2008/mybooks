// ChildView.h : CChildView 类的接口
//
#pragma once

#include <Mmsystem.h>
#include <d3dx9.h>
#include <string>

#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")

// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 属性
public:
	IDirect3DDevice9* m_Device; 
	ID3DXMesh* m_Teapot;
	float m_Angle;

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	int InitDX(void);
};

