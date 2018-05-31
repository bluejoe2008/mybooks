// GdiplusTestView.cpp : CGdiplusTestView 类的实现
//

#include "stdafx.h"

#include "gdiplus.h"
#pragma comment(lib, "gdiplus.lib")

#include "GdiplusTest.h"

#include "GdiplusTestDoc.h"
#include "GdiplusTestView.h"
using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusTestView

IMPLEMENT_DYNCREATE(CGdiplusTestView, CView)

BEGIN_MESSAGE_MAP(CGdiplusTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CGdiplusTestView 构造/析构

CGdiplusTestView::CGdiplusTestView()
{
	GdiplusStartupInput input;
	GdiplusStartup(&m_gdiplusToken, &input, NULL);
}

CGdiplusTestView::~CGdiplusTestView()
{
	GdiplusShutdown(m_gdiplusToken);
}

BOOL CGdiplusTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGdiplusTestView 绘制

void CGdiplusTestView::OnDraw(CDC* pDC)
{
	Graphics g(pDC->m_hDC);
	CRect rt;
	GetClientRect(&rt);

	//绘制白底
	SolidBrush brush(Color(255, 255, 255));
	g.FillRectangle(&brush, rt.left, rt.top, rt.right, rt.bottom);

	//绘制圆
	Pen pen(Color(255, 0, 0), 2);
	g.DrawEllipse(&pen, 100, 100, 300, 300);

	//输出文字
	CString s(_T("welcome to http://vcer.net"));
	FontFamily ff(_T("Tahoma"));
	Font font(&ff, 24, FontStyleItalic, UnitPixel);
	
	SolidBrush blue(Color(0, 0, 255));
	g.DrawString(s, s.GetLength(), &font, PointF(350, 350), &blue);
}


// CGdiplusTestView 打印

BOOL CGdiplusTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGdiplusTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGdiplusTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CGdiplusTestView 诊断

#ifdef _DEBUG
void CGdiplusTestView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusTestDoc* CGdiplusTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusTestDoc)));
	return (CGdiplusTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusTestView 消息处理程序
