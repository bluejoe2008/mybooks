// ExplorerLikeTestView.h : CExplorerLikeTestView 类的接口
//


#pragma once


class CExplorerLikeTestView : public CListView
{
protected: // 仅从序列化创建
	CExplorerLikeTestView();
	DECLARE_DYNCREATE(CExplorerLikeTestView)

// 属性
public:
	CExplorerLikeTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CExplorerLikeTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ExplorerLikeTestView.cpp 中的调试版本
inline CExplorerLikeTestDoc* CExplorerLikeTestView::GetDocument() const
   { return reinterpret_cast<CExplorerLikeTestDoc*>(m_pDocument); }
#endif

