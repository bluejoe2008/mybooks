// GdiplusTestDoc.cpp : CGdiplusTestDoc 类的实现
//

#include "stdafx.h"
#include "GdiplusTest.h"

#include "GdiplusTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusTestDoc

IMPLEMENT_DYNCREATE(CGdiplusTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiplusTestDoc, CDocument)
END_MESSAGE_MAP()


// CGdiplusTestDoc 构造/析构

CGdiplusTestDoc::CGdiplusTestDoc()
{
	// TODO: 在此添加一次性构造代码

}

CGdiplusTestDoc::~CGdiplusTestDoc()
{
}

BOOL CGdiplusTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CGdiplusTestDoc 序列化

void CGdiplusTestDoc::Serialize(CArchive& ar)
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


// CGdiplusTestDoc 诊断

#ifdef _DEBUG
void CGdiplusTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiplusTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiplusTestDoc 命令
