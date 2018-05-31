#include "stdafx.h"
#include "ResLoader.h"

CWinApp theApp;

int _tmain()
{
	int nRetCode = 0;

	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		HRSRC hRes = FindResource(theApp.m_hInstance, MAKEINTRESOURCE(IDR_WORD1), _T("WORD"));
		//获取长度
		DWORD len  = SizeofResource(theApp.m_hInstance, hRes);
		HGLOBAL hg = LoadResource(theApp.m_hInstance, hRes);
		LPVOID lp = (LPSTR)LockResource(hg); 

		//将资源中的内容保存至某个WORD文件中
		CFile file;
		file.Open(_T("out.doc"), CFile::modeWrite | CFile::modeCreate);

		char * cp = (char *)lp;
		for(int i = 0; i < len; i++)
		{
			file.Write(cp++, 1);
		}

		CString filePath = file.GetFilePath();
		file.Close();

		//打开该文件
		ShellExecute(NULL, _T("open"), filePath, NULL, NULL, SW_SHOW);
		FreeResource(hg); 
	}

	return nRetCode;
}
