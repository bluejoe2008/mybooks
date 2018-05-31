// ExplorerLikeTestView.cpp : CExplorerLikeTestView 类的实现
//

#include "stdafx.h"
#include "ExplorerLikeTest.h"

#include "ExplorerLikeTestDoc.h"
#include "ExplorerLikeTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExplorerLikeTestView

IMPLEMENT_DYNCREATE(CExplorerLikeTestView, CListView)

BEGIN_MESSAGE_MAP(CExplorerLikeTestView, CListView)
	ON_WM_STYLECHANGED()
END_MESSAGE_MAP()

// CExplorerLikeTestView 构造/析构

CExplorerLikeTestView::CExplorerLikeTestView()
{
	// TODO: 在此处添加构造代码

}

CExplorerLikeTestView::~CExplorerLikeTestView()
{
}

BOOL CExplorerLikeTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void CExplorerLikeTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}


// CExplorerLikeTestView 诊断

#ifdef _DEBUG
void CExplorerLikeTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CExplorerLikeTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CExplorerLikeTestDoc* CExplorerLikeTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExplorerLikeTestDoc)));
	return (CExplorerLikeTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CExplorerLikeTestView 消息处理程序
void CExplorerLikeTestView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: 添加代码以响应用户对窗口视图样式的更改	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}
