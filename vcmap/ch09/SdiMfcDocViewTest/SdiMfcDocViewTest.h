// SdiMfcDocViewTest.h : SdiMfcDocViewTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSdiMfcDocViewTestApp:
// �йش����ʵ�֣������ SdiMfcDocViewTest.cpp
//

class CSdiMfcDocViewTestApp : public CWinApp
{
public:
	CSdiMfcDocViewTestApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSdiMfcDocViewTestApp theApp;