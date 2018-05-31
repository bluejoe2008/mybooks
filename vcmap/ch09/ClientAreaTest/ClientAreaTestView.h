// ClientAreaTestView.h : CClientAreaTestView 类的接口
//


#pragma once


class CClientAreaTestView : public CView
{
protected: // 仅从序列化创建
	CClientAreaTestView();
	DECLARE_DYNCREATE(CClientAreaTestView)

// 属性
public:
	CClientAreaTestDoc* GetDocument() const;

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
	virtual ~CClientAreaTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseLeave();
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};

#ifndef _DEBUG  // ClientAreaTestView.cpp 中的调试版本
inline CClientAreaTestDoc* CClientAreaTestView::GetDocument() const
   { return reinterpret_cast<CClientAreaTestDoc*>(m_pDocument); }
#endif

