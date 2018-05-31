// MfcTestDoc.cpp : CMfcTestDoc 类的实现
//

#include "stdafx.h"
#include "MfcTest.h"

#include "MfcTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcTestDoc

IMPLEMENT_DYNCREATE(CMfcTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcTestDoc, CDocument)
END_MESSAGE_MAP()


// CMfcTestDoc 构造/析构

CMfcTestDoc::CMfcTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMfcTestDoc::~CMfcTestDoc()
{
}

BOOL CMfcTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMfcTestDoc 序列化

void CMfcTestDoc::Serialize(CArchive& ar)
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


// CMfcTestDoc 诊断

#ifdef _DEBUG
void CMfcTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMfcTestDoc 命令
