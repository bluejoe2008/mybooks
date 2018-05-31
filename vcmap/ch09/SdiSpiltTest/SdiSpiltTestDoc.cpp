// SdiSpiltTestDoc.cpp : CSdiSpiltTestDoc 类的实现
//

#include "stdafx.h"
#include "SdiSpiltTest.h"

#include "SdiSpiltTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSpiltTestDoc

IMPLEMENT_DYNCREATE(CSdiSpiltTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiSpiltTestDoc, CDocument)
END_MESSAGE_MAP()


// CSdiSpiltTestDoc 构造/析构

CSdiSpiltTestDoc::CSdiSpiltTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CSdiSpiltTestDoc::~CSdiSpiltTestDoc()
{
}

BOOL CSdiSpiltTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSdiSpiltTestDoc 序列化

void CSdiSpiltTestDoc::Serialize(CArchive& ar)
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


// CSdiSpiltTestDoc 诊断

#ifdef _DEBUG
void CSdiSpiltTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiSpiltTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSdiSpiltTestDoc 命令
