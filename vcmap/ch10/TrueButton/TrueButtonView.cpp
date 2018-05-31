// TrueButtonView.cpp : CTrueButtonView 类的实现
//

#include "stdafx.h"
#include "TrueButton.h"

#include "TrueButtonDoc.h"
#include "TrueButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrueButtonView

IMPLEMENT_DYNCREATE(CTrueButtonView, CView)

BEGIN_MESSAGE_MAP(CTrueButtonView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CTrueButtonView 构造/析构

CTrueButtonView::CTrueButtonView()
{
	// TODO: 在此处添加构造代码

}

CTrueButtonView::~CTrueButtonView()
{
}

BOOL CTrueButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTrueButtonView 绘制

void CTrueButtonView::OnDraw(CDC* /*pDC*/)
{
	CTrueButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTrueButtonView 打印

BOOL CTrueButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTrueButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTrueButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTrueButtonView 诊断

#ifdef _DEBUG
void CTrueButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CTrueButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrueButtonDoc* CTrueButtonView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrueButtonDoc)));
	return (CTrueButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CTrueButtonView 消息处理程序

int CTrueButtonView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//创建一个真正的按钮！
	m_Button.Create(_T("Hello, World!"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(100, 110, 220, 150), this, 1000);
	//创建一个真正的文本标签！
	m_Static.Create(_T("welcome to http://vcer.net"), WS_CHILD | WS_VISIBLE | SS_CENTER | SS_SUNKEN, CRect(350, 350, 450, 400), this);

	return 0;
}
