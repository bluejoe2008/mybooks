// MyCircleView.h : CMyCircleView 类的接口
//


#pragma once


class CMyCircleView : public CView
{
protected: // 仅从序列化创建
	CMyCircleView();
	DECLARE_DYNCREATE(CMyCircleView)

// 属性
public:
	CMyCircleDoc* GetDocument() const;

// 操作
public:

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
	virtual ~CMyCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MyCircleView.cpp 中的调试版本
inline CMyCircleDoc* CMyCircleView::GetDocument() const
   { return reinterpret_cast<CMyCircleDoc*>(m_pDocument); }
#endif

