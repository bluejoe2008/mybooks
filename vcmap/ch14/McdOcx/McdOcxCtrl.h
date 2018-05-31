#pragma once

// McdOcxCtrl.h : CMcdOcxCtrl ActiveX 控件类的声明。


// CMcdOcxCtrl : 有关实现的信息，请参阅 McdOcxCtrl.cpp。

class CMcdOcxCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMcdOcxCtrl)

// 构造函数
public:
	CMcdOcxCtrl();

// 重写
public:
	int _a;
	int _b;

	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CMcdOcxCtrl();

	DECLARE_OLECREATE_EX(CMcdOcxCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CMcdOcxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMcdOcxCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CMcdOcxCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidDirection = 2,
		dispidSetNumbers = 1L
	};
private:
	int _mcd(int a, int b);
protected:
	void SetNumbers(SHORT a, SHORT b);
	void OnDirectionChanged(void);
	SHORT m_Direction;
};

