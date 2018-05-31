// FakeButtonDoc.cpp : CFakeButtonDoc 类的实现
//

#include "stdafx.h"
#include "FakeButton.h"

#include "FakeButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFakeButtonDoc

IMPLEMENT_DYNCREATE(CFakeButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CFakeButtonDoc, CDocument)
END_MESSAGE_MAP()


// CFakeButtonDoc 构造/析构

CFakeButtonDoc::CFakeButtonDoc()
{
	// TODO: 在此添加一次性构造代码

}

CFakeButtonDoc::~CFakeButtonDoc()
{
}

BOOL CFakeButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CFakeButtonDoc 序列化

void CFakeButtonDoc::Serialize(CArchive& ar)
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


// CFakeButtonDoc 诊断

#ifdef _DEBUG
void CFakeButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFakeButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFakeButtonDoc 命令
