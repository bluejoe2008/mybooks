// SdiMfcDocViewTestView.cpp : CSdiMfcDocViewTestView 类的实现
//

#include "stdafx.h"
#include "SdiMfcDocViewTest.h"

#include "SdiMfcDocViewTestDoc.h"
#include "SdiMfcDocViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiMfcDocViewTestView

IMPLEMENT_DYNCREATE(CSdiMfcDocViewTestView, CView)

BEGIN_MESSAGE_MAP(CSdiMfcDocViewTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSdiMfcDocViewTestView 构造/析构

CSdiMfcDocViewTestView::CSdiMfcDocViewTestView()
{
	// TODO: 在此处添加构造代码

}

CSdiMfcDocViewTestView::~CSdiMfcDocViewTestView()
{
}

BOOL CSdiMfcDocViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSdiMfcDocViewTestView 绘制

void CSdiMfcDocViewTestView::OnDraw(CDC* /*pDC*/)
{
	CSdiMfcDocViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CSdiMfcDocViewTestView 打印

BOOL CSdiMfcDocViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSdiMfcDocViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSdiMfcDocViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSdiMfcDocViewTestView 诊断

#ifdef _DEBUG
void CSdiMfcDocViewTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiMfcDocViewTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiMfcDocViewTestDoc* CSdiMfcDocViewTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiMfcDocViewTestDoc)));
	return (CSdiMfcDocViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiMfcDocViewTestView 消息处理程序
