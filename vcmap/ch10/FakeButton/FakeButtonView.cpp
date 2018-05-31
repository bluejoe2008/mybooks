// FakeButtonView.cpp : CFakeButtonView 类的实现
//

#include "stdafx.h"
#include "FakeButton.h"

#include "FakeButtonDoc.h"
#include "FakeButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFakeButtonView

IMPLEMENT_DYNCREATE(CFakeButtonView, CView)

BEGIN_MESSAGE_MAP(CFakeButtonView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFakeButtonView 构造/析构

CFakeButtonView::CFakeButtonView()
{
	// TODO: 在此处添加构造代码

}

CFakeButtonView::~CFakeButtonView()
{
}

BOOL CFakeButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFakeButtonView 绘制

void CFakeButtonView::OnDraw(CDC* pDC)
{
	//绘制命令按钮
	CRect rt(100, 110, 220, 150);
	pDC->DrawFrameControl(rt, DFC_BUTTON, DFCS_BUTTONPUSH);

	//输出文字
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(120, 120, _T("Hello, World!"));
	rt.DeflateRect(3, 3);
	pDC->DrawFocusRect(rt);

	//复选框
	pDC->DrawFrameControl(CRect(100, 180, 220, 194), DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
	//单选框
	pDC->DrawFrameControl(CRect(100, 200, 220, 214), DFC_BUTTON, DFCS_BUTTONRADIO | DFCS_CHECKED);

	//滚动条
	pDC->DrawFrameControl(CRect(100, 220, 220, 240), DFC_SCROLL, DFCS_SCROLLUP);
	pDC->DrawFrameControl(CRect(100, 240, 220, 260), DFC_SCROLL, DFCS_SCROLLDOWN);
}


// CFakeButtonView 打印

BOOL CFakeButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFakeButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFakeButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFakeButtonView 诊断

#ifdef _DEBUG
void CFakeButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CFakeButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFakeButtonDoc* CFakeButtonView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFakeButtonDoc)));
	return (CFakeButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CFakeButtonView 消息处理程序
