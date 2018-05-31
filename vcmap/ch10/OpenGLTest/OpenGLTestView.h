// OpenGLTestView.h : COpenGLTestView 类的接口
//


#pragma once

class COpenGLTestView : public CView
{
protected: // 仅从序列化创建
	COpenGLTestView();
	DECLARE_DYNCREATE(COpenGLTestView)

// 属性
public:
	int m_GLPixelIndex;
	HGLRC m_hGLContext;
	COpenGLTestDoc* GetDocument() const;

// 操作
public:
	BOOL SetWindowPixelFormat(HDC hDC);
	BOOL CreateViewGLContext(HDC hDC);
	void RenderScene(void);

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~COpenGLTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // OpenGLTestView.cpp 中的调试版本
inline COpenGLTestDoc* COpenGLTestView::GetDocument() const
   { return reinterpret_cast<COpenGLTestDoc*>(m_pDocument); }
#endif

