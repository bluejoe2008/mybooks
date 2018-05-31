// MyCircleView.cpp : CMyCircleView 类的实现
//

#include "stdafx.h"
#include "MyCircle.h"

#include "MyCircleDoc.h"
#include "MyCircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyCircleView

IMPLEMENT_DYNCREATE(CMyCircleView, CView)

BEGIN_MESSAGE_MAP(CMyCircleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_CREATE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMyCircleView 构造/析构

CMyCircleView::CMyCircleView()
{
	// TODO: 在此处添加构造代码

}

CMyCircleView::~CMyCircleView()
{
}

BOOL CMyCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyCircleView 绘制

void CMyCircleView::OnDraw(CDC* pDC)
{
	//获取最大尺寸
	CRect rt;
	GetClientRect(&rt);
	
	//绘制白底
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	pDC->FillRect(&rt, &brush);

	//绘制圆
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen * pOldPen = pDC->SelectObject(&pen);
	pDC->Ellipse(100, 100, 300, 300);

	//输出文字
	CFont font;
	font.CreatePointFont(200, _T("Tahoma"));
	CFont * pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOut(350, 350, CString(_T("welcome to http://vcer.net")));

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldFont);
}


// CMyCircleView 打印

BOOL CMyCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMyCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMyCircleView 诊断

#ifdef _DEBUG
void CMyCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CMyCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCircleDoc* CMyCircleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCircleDoc)));
	return (CMyCircleDoc*)m_pDocument;
}
#endif //_DEBUG

void CMyCircleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}
