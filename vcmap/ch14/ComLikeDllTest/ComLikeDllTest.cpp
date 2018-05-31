#include "stdafx.h"
#include "../ComLikeDll/ComLikeDll.h"
#include "../ComLikeDll/IPhone.h"
#include "../ComLikeDll/Native.h"

#pragma comment(lib, "../Debug/ComLikeDll.lib")

int _tmain()
{
	IUnknown * pu;
	CreateObject(NATIVE_MOBILE_PHONE, (void **)&pu);

	IMobilePhone * pmp1;
	pu->QueryInterface(MOBILE_PHONE_PART, (void **)&pmp1);
	pmp1->talk();

	IMp3Player * pmp2;
	pu->QueryInterface(NATIVE_MOBILE_PHONE, (void **)&pmp2);
	pmp2->play("´º½­»¨ÔÂÒ¹");

	pu->Release();
	return 0;
}
