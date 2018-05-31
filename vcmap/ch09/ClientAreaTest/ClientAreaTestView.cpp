// ClientAreaTestView.cpp : CClientAreaTestView 类的实现
//

#include "stdafx.h"
#include "ClientAreaTest.h"
#include "MainFrm.h"

#include "ClientAreaTestDoc.h"
#include "ClientAreaTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientAreaTestView

IMPLEMENT_DYNCREATE(CClientAreaTestView, CView)

BEGIN_MESSAGE_MAP(CClientAreaTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_NCMOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CClientAreaTestView 构造/析构

CClientAreaTestView::CClientAreaTestView()
{
	// TODO: 在此处添加构造代码

}

CClientAreaTestView::~CClientAreaTestView()
{
}

BOOL CClientAreaTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CClientAreaTestView 绘制

void CClientAreaTestView::OnDraw(CDC* /*pDC*/)
{
	CClientAreaTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CClientAreaTestView 打印

BOOL CClientAreaTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CClientAreaTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CClientAreaTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CClientAreaTestView 诊断

#ifdef _DEBUG
void CClientAreaTestView::AssertValid() const
{
	CView::AssertValid();
}

void CClientAreaTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClientAreaTestDoc* CClientAreaTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientAreaTestDoc)));
	return (CClientAreaTestDoc*)m_pDocument;
}
#endif //_DEBUG

void CClientAreaTestView::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CView::OnNcMouseMove(nHitTest, point);
}

void CClientAreaTestView::OnMouseMove(UINT nFlags, CPoint point)
{
	((CMainFrame *)(this->GetParentFrame()->GetParentFrame()))->ShowStatus(_T(__FUNCTION__), point);
	CView::OnMouseMove(nFlags, point);
}