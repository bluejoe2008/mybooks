// TrueButtonView.h : CTrueButtonView 类的接口
//


#pragma once


class CTrueButtonView : public CView
{
protected: // 仅从序列化创建
	CTrueButtonView();
	DECLARE_DYNCREATE(CTrueButtonView)

// 属性
public:
	CTrueButtonDoc* GetDocument() const;
	CButton m_Button;
	CStatic m_Static;

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
	virtual ~CTrueButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // TrueButtonView.cpp 中的调试版本
inline CTrueButtonDoc* CTrueButtonView::GetDocument() const
   { return reinterpret_cast<CTrueButtonDoc*>(m_pDocument); }
#endif

