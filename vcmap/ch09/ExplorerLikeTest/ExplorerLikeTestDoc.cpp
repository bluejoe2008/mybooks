// ExplorerLikeTestDoc.cpp : CExplorerLikeTestDoc 类的实现
//

#include "stdafx.h"
#include "ExplorerLikeTest.h"

#include "ExplorerLikeTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExplorerLikeTestDoc

IMPLEMENT_DYNCREATE(CExplorerLikeTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CExplorerLikeTestDoc, CDocument)
END_MESSAGE_MAP()


// CExplorerLikeTestDoc 构造/析构

CExplorerLikeTestDoc::CExplorerLikeTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CExplorerLikeTestDoc::~CExplorerLikeTestDoc()
{
}

BOOL CExplorerLikeTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CExplorerLikeTestDoc 序列化

void CExplorerLikeTestDoc::Serialize(CArchive& ar)
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


// CExplorerLikeTestDoc 诊断

#ifdef _DEBUG
void CExplorerLikeTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExplorerLikeTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExplorerLikeTestDoc 命令
