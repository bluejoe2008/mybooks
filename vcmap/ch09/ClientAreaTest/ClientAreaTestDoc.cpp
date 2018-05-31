// ClientAreaTestDoc.cpp : CClientAreaTestDoc 类的实现
//

#include "stdafx.h"
#include "ClientAreaTest.h"

#include "ClientAreaTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientAreaTestDoc

IMPLEMENT_DYNCREATE(CClientAreaTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CClientAreaTestDoc, CDocument)
END_MESSAGE_MAP()


// CClientAreaTestDoc 构造/析构

CClientAreaTestDoc::CClientAreaTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CClientAreaTestDoc::~CClientAreaTestDoc()
{
}

BOOL CClientAreaTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CClientAreaTestDoc 序列化

void CClientAreaTestDoc::Serialize(CArchive& ar)
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


// CClientAreaTestDoc 诊断

#ifdef _DEBUG
void CClientAreaTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClientAreaTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CClientAreaTestDoc 命令
