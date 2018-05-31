// SdiSpiltTestView.cpp : CSdiSpiltTestView 类的实现
//

#include "stdafx.h"
#include "SdiSpiltTest.h"

#include "SdiSpiltTestDoc.h"
#include "SdiSpiltTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSpiltTestView

IMPLEMENT_DYNCREATE(CSdiSpiltTestView, CView)

BEGIN_MESSAGE_MAP(CSdiSpiltTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSdiSpiltTestView 构造/析构

CSdiSpiltTestView::CSdiSpiltTestView()
{
	// TODO: 在此处添加构造代码

}

CSdiSpiltTestView::~CSdiSpiltTestView()
{
}

BOOL CSdiSpiltTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSdiSpiltTestView 绘制

void CSdiSpiltTestView::OnDraw(CDC* pDC)
{
	//画圆
	CRect rt;
	this->GetClientRect(&rt);
	pDC->Ellipse(&rt);
}


// CSdiSpiltTestView 打印

BOOL CSdiSpiltTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSdiSpiltTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSdiSpiltTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSdiSpiltTestView 诊断

#ifdef _DEBUG
void CSdiSpiltTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiSpiltTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiSpiltTestDoc* CSdiSpiltTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSpiltTestDoc)));
	return (CSdiSpiltTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSpiltTestView 消息处理程序
