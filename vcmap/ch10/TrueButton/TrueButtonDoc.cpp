// TrueButtonDoc.cpp : CTrueButtonDoc 类的实现
//

#include "stdafx.h"
#include "TrueButton.h"

#include "TrueButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrueButtonDoc

IMPLEMENT_DYNCREATE(CTrueButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrueButtonDoc, CDocument)
END_MESSAGE_MAP()


// CTrueButtonDoc 构造/析构

CTrueButtonDoc::CTrueButtonDoc()
{
	// TODO: 在此添加一次性构造代码

}

CTrueButtonDoc::~CTrueButtonDoc()
{
}

BOOL CTrueButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTrueButtonDoc 序列化

void CTrueButtonDoc::Serialize(CArchive& ar)
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


// CTrueButtonDoc 诊断

#ifdef _DEBUG
void CTrueButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrueButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTrueButtonDoc 命令
