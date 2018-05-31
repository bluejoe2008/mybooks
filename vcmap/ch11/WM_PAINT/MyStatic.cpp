// MyStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "WM_PAINT.h"
#include "MyStatic.h"


// CMyStatic

IMPLEMENT_DYNAMIC(CMyStatic, CStatic)

CMyStatic::CMyStatic()
{

}

CMyStatic::~CMyStatic()
{
}


BEGIN_MESSAGE_MAP(CMyStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyStatic 消息处理程序



void CMyStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//什么都不输出，仅仅画一个矩形框
	CRect rc;
	GetClientRect(&rc);
	dc.DrawFrameControl(&rc, DFC_CAPTION, DFCS_CAPTIONHELP);
}
