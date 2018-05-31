#pragma once

// McdOcxPropPage.h : CMcdOcxPropPage 属性页类的声明。


// CMcdOcxPropPage : 有关实现的信息，请参阅 McdOcxPropPage.cpp。

class CMcdOcxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMcdOcxPropPage)
	DECLARE_OLECREATE_EX(CMcdOcxPropPage)

// 构造函数
public:
	CMcdOcxPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MCDOCX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

