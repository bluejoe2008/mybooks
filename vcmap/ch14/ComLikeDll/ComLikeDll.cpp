// ComLikeDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "ComLikeDll.h"
#include "Native.h"

bool _declspec(dllexport) CreateObject(int type, void ** ppObject)
{
	if(type == NATIVE_MOBILE_PHONE)
	{
		*ppObject = new NativeMobilePhone();
	}

	return true;
}
