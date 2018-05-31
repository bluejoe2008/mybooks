#include "stdafx.h"
#include "../MobilePhoneCom/MobilePhoneCom.h"
#include "../MobilePhoneCom/MobilePhoneCom_i.c"
#include "comutil.h"
#pragma comment( lib, "comsuppw.lib" )

#include <iostream>
using namespace std;

int _tmain()
{
	HRESULT hr = CoInitialize(NULL);
	if(SUCCEEDED(hr))
	{
		IMobilePhone * ptrMobilePhone;
		hr = CoCreateInstance(CLSID_MobilePhone, NULL, CLSCTX_INPROC_SERVER, IID_IMobilePhone, (void **)&ptrMobilePhone);
		if(SUCCEEDED(hr))
		{
			_bstr_t cb;
			ptrMobilePhone->getName(&cb.GetBSTR());

			cout << "»úÆ÷Ãû³Æ: " << (char *)cb << endl;
			ptrMobilePhone->talk();
			//ptrMobilePhone->Release();
		}
	}
	CoUninitialize();
	return 0;
}