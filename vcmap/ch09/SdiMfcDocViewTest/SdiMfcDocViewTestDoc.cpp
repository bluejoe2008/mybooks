// SdiMfcDocViewTestDoc.cpp : CSdiMfcDocViewTestDoc 类的实现
//

#include "stdafx.h"
#include "SdiMfcDocViewTest.h"

#include "SdiMfcDocViewTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiMfcDocViewTestDoc

IMPLEMENT_DYNCREATE(CSdiMfcDocViewTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiMfcDocViewTestDoc, CDocument)
END_MESSAGE_MAP()


// CSdiMfcDocViewTestDoc 构造/析构

CSdiMfcDocViewTestDoc::CSdiMfcDocViewTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSdiMfcDocViewTestDoc::~CSdiMfcDocViewTestDoc()
{
}

BOOL CSdiMfcDocViewTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSdiMfcDocViewTestDoc 序列化

void CSdiMfcDocViewTestDoc::Serialize(CArchive& ar)
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


// CSdiMfcDocViewTestDoc 诊断

#ifdef _DEBUG
void CSdiMfcDocViewTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiMfcDocViewTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSdiMfcDocViewTestDoc 命令
