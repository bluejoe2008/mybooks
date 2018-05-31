// MyCircleDoc.cpp : CMyCircleDoc 类的实现
//

#include "stdafx.h"
#include "MyCircle.h"

#include "MyCircleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyCircleDoc

IMPLEMENT_DYNCREATE(CMyCircleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyCircleDoc, CDocument)
END_MESSAGE_MAP()


// CMyCircleDoc 构造/析构

CMyCircleDoc::CMyCircleDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMyCircleDoc::~CMyCircleDoc()
{
}

BOOL CMyCircleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMyCircleDoc 序列化

void CMyCircleDoc::Serialize(CArchive& ar)
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


// CMyCircleDoc 诊断

#ifdef _DEBUG
void CMyCircleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyCircleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyCircleDoc 命令
