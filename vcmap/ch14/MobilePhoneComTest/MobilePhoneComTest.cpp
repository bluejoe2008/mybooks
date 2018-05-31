// MobilePhoneComTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "comutil.h"
#include <iostream>
using namespace std;

#import "..\\MobilePhoneCom\\Debug\\MobilePhoneCom.dll"

int _tmain()
{
	HRESULT hr = CoInitialize(NULL);
	if(SUCCEEDED(hr))
	{
		MobilePhoneComLib::IMobilePhonePtr ptrMobilePhone;
		if(SUCCEEDED(ptrMobilePhone.CreateInstance(__uuidof(MobilePhoneComLib::MobilePhone))))
		{
			_bstr_t cb;
			cb = ptrMobilePhone->getName();

			cout << "机器名称: " << (char *)cb << endl;
			ptrMobilePhone->talk();
		}
	}

	CoUninitialize();
	return 0;
}

