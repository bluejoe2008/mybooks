// OpenGLTestView.cpp : COpenGLTestView 类的实现
//

#include "stdafx.h"
#include "OpenGLTest.h"

#include "OpenGLTestDoc.h"
#include "OpenGLTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLTestView

IMPLEMENT_DYNCREATE(COpenGLTestView, CView)

BEGIN_MESSAGE_MAP(COpenGLTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// COpenGLTestView 构造/析构

COpenGLTestView::COpenGLTestView()
{
	m_hGLContext = NULL;
	m_GLPixelIndex = 0;
}

COpenGLTestView::~COpenGLTestView()
{
}

BOOL COpenGLTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);

	return CView::PreCreateWindow(cs);
}

BOOL COpenGLTestView::SetWindowPixelFormat(HDC hDC)
{
	PIXELFORMATDESCRIPTOR pixelDesc;
	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;
	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | 
		PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL | 
		PFD_SUPPORT_GDI |PFD_STEREO_DONTCARE;
	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 32; 
	pixelDesc.cRedBits = 8;
	pixelDesc.cRedShift = 16;
	pixelDesc.cGreenBits = 8;
	pixelDesc.cGreenShift = 8;
	pixelDesc.cBlueBits = 8;
	pixelDesc.cBlueShift = 0; 
	pixelDesc.cAlphaBits = 0;
	pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits= 64; 
	pixelDesc.cAccumRedBits = 16;
	pixelDesc.cAccumGreenBits = 16;
	pixelDesc.cAccumBlueBits = 16;
	pixelDesc.cAccumAlphaBits= 0;
	pixelDesc.cDepthBits = 32; 
	pixelDesc.cStencilBits= 8;
	pixelDesc.cAuxBuffers = 0; 
	pixelDesc.iLayerType= PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0; 
	pixelDesc.dwLayerMask= 0;
	pixelDesc.dwVisibleMask= 0;
	pixelDesc.dwDamageMask= 0;
	m_GLPixelIndex = ChoosePixelFormat( hDC, &pixelDesc);
	if (m_GLPixelIndex==0) // Let's choose a default index.
	{
		m_GLPixelIndex = 1; 
		if (DescribePixelFormat(hDC, m_GLPixelIndex, sizeof
			(PIXELFORMATDESCRIPTOR), &pixelDesc)==0)
		{
			return FALSE;
		}
	}
	if (SetPixelFormat( hDC, m_GLPixelIndex, 
		&pixelDesc)==FALSE)
	{
		return FALSE;
	}
	return TRUE;
}

// COpenGLTestView 绘制

void COpenGLTestView::OnDraw(CDC* /*pDC*/)
{
	COpenGLTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->RenderScene();
}


// COpenGLTestView 打印

BOOL COpenGLTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void COpenGLTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void COpenGLTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// COpenGLTestView 诊断

#ifdef _DEBUG
void COpenGLTestView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLTestDoc* COpenGLTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLTestDoc)));
	return (COpenGLTestDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenGLTestView 消息处理程序

void COpenGLTestView::OnDestroy()
{
	if(wglGetCurrentContext()!=NULL) 
	{
		wglMakeCurrent(NULL, NULL) ;
	}
	if (m_hGLContext!=NULL)
	{
		wglDeleteContext(m_hGLContext);
		m_hGLContext = NULL;
	}
	CView::OnDestroy();
}

BOOL COpenGLTestView::CreateViewGLContext(HDC hDC)
{
	m_hGLContext = wglCreateContext(hDC);
	if (m_hGLContext == NULL)
	{
		return FALSE;
	}
	if (wglMakeCurrent(hDC, m_hGLContext)==FALSE)
	{
		return FALSE;
	}
	return TRUE;
}

int COpenGLTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	HWND hWnd = GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);
	if (SetWindowPixelFormat(hDC)==FALSE)
		return 0;
	if (CreateViewGLContext(hDC)==FALSE)
		return 0;

	return 0;
}

BOOL COpenGLTestView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void COpenGLTestView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	GLsizei width, height; GLdouble aspect;
	width = cx; height = cy;
	if (cy==0)
		aspect = (GLdouble)width;
	else
		aspect = (GLdouble)width/(GLdouble)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, aspect, 1, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
