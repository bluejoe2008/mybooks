// ControlBarTestView.cpp : CControlBarTestView 类的实现
//

#include "stdafx.h"
#include "ControlBarTest.h"

#include "ControlBarTestDoc.h"
#include "ControlBarTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlBarTestView

IMPLEMENT_DYNCREATE(CControlBarTestView, CView)

BEGIN_MESSAGE_MAP(CControlBarTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CControlBarTestView 构造/析构

CControlBarTestView::CControlBarTestView()
{
	// TODO: 在此处添加构造代码

}

CControlBarTestView::~CControlBarTestView()
{
}

BOOL CControlBarTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CControlBarTestView 绘制

void CControlBarTestView::OnDraw(CDC* /*pDC*/)
{
	CControlBarTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CControlBarTestView 打印

BOOL CControlBarTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CControlBarTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CControlBarTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CControlBarTestView 诊断

#ifdef _DEBUG
void CControlBarTestView::AssertValid() const
{
	CView::AssertValid();
}

void CControlBarTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControlBarTestDoc* CControlBarTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControlBarTestDoc)));
	return (CControlBarTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CControlBarTestView 消息处理程序
