// ChildFrm.cpp : CChildFrame 类的实现
//
#include "stdafx.h"
#include "ClientAreaTest.h"

#include "ChildFrm.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_WM_NCMOUSEMOVE()
	//ON_WM_NCMOUSELEAVE()
	//ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO: 在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame 消息处理程序

void CChildFrame::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CMDIChildWnd::OnNcMouseMove(nHitTest, point);
}

void CChildFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CMDIChildWnd::OnMouseMove(nFlags, point);
}
