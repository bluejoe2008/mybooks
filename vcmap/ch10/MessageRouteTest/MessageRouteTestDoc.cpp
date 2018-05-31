// MessageRouteTestDoc.cpp : CMessageRouteTestDoc 类的实现
//

#include "stdafx.h"
#include "MessageRouteTest.h"

#include "MessageRouteTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessageRouteTestDoc

IMPLEMENT_DYNCREATE(CMessageRouteTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMessageRouteTestDoc, CDocument)
	//ON_COMMAND(ID_FILE_OPEN, &CMessageRouteTestDoc::OnFileOpen)
END_MESSAGE_MAP()


// CMessageRouteTestDoc 构造/析构

CMessageRouteTestDoc::CMessageRouteTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMessageRouteTestDoc::~CMessageRouteTestDoc()
{
}

BOOL CMessageRouteTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMessageRouteTestDoc 序列化

void CMessageRouteTestDoc::Serialize(CArchive& ar)
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


// CMessageRouteTestDoc 诊断

#ifdef _DEBUG
void CMessageRouteTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMessageRouteTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMessageRouteTestDoc 命令

void CMessageRouteTestDoc::OnFileOpen()
{
	::MessageBox(NULL, _T(__FUNCTION__), _T(""), MB_OK);
}
