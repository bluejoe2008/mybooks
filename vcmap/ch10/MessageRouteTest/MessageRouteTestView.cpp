// MessageRouteTestView.cpp : CMessageRouteTestView 类的实现
//

#include "stdafx.h"
#include "MessageRouteTest.h"

#include "MessageRouteTestDoc.h"
#include "MessageRouteTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessageRouteTestView

IMPLEMENT_DYNCREATE(CMessageRouteTestView, CView)

BEGIN_MESSAGE_MAP(CMessageRouteTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//ON_COMMAND(ID_FILE_OPEN, &CMessageRouteTestView::OnFileOpen)
END_MESSAGE_MAP()

// CMessageRouteTestView 构造/析构

CMessageRouteTestView::CMessageRouteTestView()
{
	// TODO: 在此处添加构造代码

}

CMessageRouteTestView::~CMessageRouteTestView()
{
}

BOOL CMessageRouteTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMessageRouteTestView 绘制

void CMessageRouteTestView::OnDraw(CDC* /*pDC*/)
{
	CMessageRouteTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMessageRouteTestView 打印

BOOL CMessageRouteTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMessageRouteTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMessageRouteTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMessageRouteTestView 诊断

#ifdef _DEBUG
void CMessageRouteTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMessageRouteTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessageRouteTestDoc* CMessageRouteTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessageRouteTestDoc)));
	return (CMessageRouteTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessageRouteTestView 消息处理程序

void CMessageRouteTestView::OnFileOpen()
{
	::MessageBox(NULL, _T(__FUNCTION__), _T(""), MB_OK);
}
