// McdOcxCtrl.cpp : CMcdOcxCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "McdOcx.h"
#include "McdOcxCtrl.h"
#include "McdOcxPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CMcdOcxCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CMcdOcxCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CMcdOcxCtrl, COleControl)
	DISP_FUNCTION_ID(CMcdOcxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMcdOcxCtrl, "SetNumbers", dispidSetNumbers, SetNumbers, VT_EMPTY, VTS_I2 VTS_I2)
	DISP_PROPERTY_NOTIFY_ID(CMcdOcxCtrl, "Direction", dispidDirection, m_Direction, OnDirectionChanged, VT_I2)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CMcdOcxCtrl, COleControl)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CMcdOcxCtrl, 1)
	PROPPAGEID(CMcdOcxPropPage::guid)
END_PROPPAGEIDS(CMcdOcxCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMcdOcxCtrl, "MCDOCX.McdOcxCtrl.1",
	0x1a1b254e, 0xd5aa, 0x406f, 0xa8, 0xb6, 0xa0, 0x21, 0x8e, 0x88, 0x43, 0xcc)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CMcdOcxCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID BASED_CODE IID_DMcdOcx =
		{ 0xF7C37EC0, 0xEA78, 0x45D9, { 0x8F, 0x6, 0x82, 0x4E, 0xBD, 0xAA, 0x52, 0xE5 } };
const IID BASED_CODE IID_DMcdOcxEvents =
		{ 0x39D92FC9, 0x5F9D, 0x452F, { 0x92, 0x3F, 0x83, 0xE7, 0xB8, 0x3A, 0xD3, 0xEB } };



// 控件类型信息

static const DWORD BASED_CODE _dwMcdOcxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMcdOcxCtrl, IDS_MCDOCX, _dwMcdOcxOleMisc)



// CMcdOcxCtrl::CMcdOcxCtrlFactory::UpdateRegistry -
// 添加或移除 CMcdOcxCtrl 的系统注册表项

BOOL CMcdOcxCtrl::CMcdOcxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MCDOCX,
			IDB_MCDOCX,
			afxRegApartmentThreading,
			_dwMcdOcxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CMcdOcxCtrl::CMcdOcxCtrl - 构造函数

CMcdOcxCtrl::CMcdOcxCtrl()
{
	InitializeIIDs(&IID_DMcdOcx, &IID_DMcdOcxEvents);
	_a = 12;
	_b = 16;
	m_Direction = 0;
}



// CMcdOcxCtrl::~CMcdOcxCtrl - 析构函数

CMcdOcxCtrl::~CMcdOcxCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CMcdOcxCtrl::OnDraw - 绘图函数

void CMcdOcxCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	//打印mcd()运算结果
	CBrush brush1, brush2;
	//清空背景
	brush1.CreateSolidBrush(0xFFFFFF);
	pdc->FillRect(rcBounds, &brush1);

	brush2.CreateSolidBrush(0x000000);
	pdc->SelectObject(brush2);

	//3个圆心
	POINT p1 = {35, m_Direction == 1 ? 100 : 40};
	POINT p2 = {195, p1.y};
	POINT p3 = {(p1.x + p2.x) / 2, m_Direction == 1 ? p1.y - 60 : p1.y + 60};
	int radius = 15;

	//绘制3个圆
	pdc->Ellipse(p1.x - radius, p1.y - radius, p1.x + radius, p1.y + radius);
	pdc->Ellipse(p2.x - radius, p2.y - radius, p2.x + radius, p2.y + radius);
	pdc->Ellipse(p3.x - radius, p3.y - radius, p3.x + radius, p3.y + radius);

	//连线
	pdc->MoveTo(p1);
	pdc->LineTo(p3);
	pdc->LineTo(p2);

	CString msg;
	pdc->SetBkMode(TRANSPARENT);
	pdc->SetTextAlign(TA_CENTER);

	//输出数字
	pdc->SetTextColor(0xFFFFFF);
	msg.Format(_T("%d"), _a);
	pdc->TextOut(p1.x, p1.y - 9, msg, msg.GetLength());
	msg.Format(_T("%d"), _b);
	pdc->TextOut(p2.x, p2.y - 9, msg, msg.GetLength());
	msg.Format(_T("%d"), _mcd(_a, _b));
	pdc->TextOut(p3.x, p3.y - 9, msg, msg.GetLength());
}


// CMcdOcxCtrl::DoPropExchange - 持久性支持

void CMcdOcxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}



// CMcdOcxCtrl::OnResetState - 将控件重置为默认状态

void CMcdOcxCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CMcdOcxCtrl::AboutBox - 向用户显示“关于”框

void CMcdOcxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_MCDOCX);
	dlgAbout.DoModal();
}



// CMcdOcxCtrl 消息处理程序

int CMcdOcxCtrl::_mcd(int a, int b)
{
	if (b == 0)
		return a;

	return _mcd(b, a % b);
}

void CMcdOcxCtrl::SetNumbers(SHORT a, SHORT b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	_a = a;
	_b = b;
	Invalidate();
}

void CMcdOcxCtrl::OnDirectionChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	Invalidate();
	SetModifiedFlag();
}
