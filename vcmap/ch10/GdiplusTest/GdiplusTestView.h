// GdiplusTestView.h : CGdiplusTestView 类的接口
//


#pragma once


class CGdiplusTestView : public CView
{
protected: // 仅从序列化创建
	CGdiplusTestView();
	DECLARE_DYNCREATE(CGdiplusTestView)

// 属性
public:
	CGdiplusTestDoc* GetDocument() const;
	ULONG_PTR m_gdiplusToken;

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
	virtual ~CGdiplusTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // GdiplusTestView.cpp 中的调试版本
inline CGdiplusTestDoc* CGdiplusTestView::GetDocument() const
   { return reinterpret_cast<CGdiplusTestDoc*>(m_pDocument); }
#endif

