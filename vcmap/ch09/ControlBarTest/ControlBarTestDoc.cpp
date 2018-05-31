// ControlBarTestDoc.cpp : CControlBarTestDoc 类的实现
//

#include "stdafx.h"
#include "ControlBarTest.h"

#include "ControlBarTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlBarTestDoc

IMPLEMENT_DYNCREATE(CControlBarTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CControlBarTestDoc, CDocument)
END_MESSAGE_MAP()


// CControlBarTestDoc 构造/析构

CControlBarTestDoc::CControlBarTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CControlBarTestDoc::~CControlBarTestDoc()
{
}

BOOL CControlBarTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CControlBarTestDoc 序列化

void CControlBarTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CControlBarTestDoc 诊断

#ifdef _DEBUG
void CControlBarTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CControlBarTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CControlBarTestDoc 命令
