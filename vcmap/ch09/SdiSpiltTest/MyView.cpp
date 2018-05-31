// MyView.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiSpiltTest.h"
#include "MyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CView)
END_MESSAGE_MAP()


// CMyView 绘图

void CMyView::OnDraw(CDC* pDC)
{
	//画关闭按钮
	CRect rt;
	this->GetClientRect(&rt);
	pDC->DrawFrameControl(&rt, DFC_CAPTION, DFCS_CAPTIONCLOSE);
}


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView 消息处理程序
