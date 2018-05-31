// MobilePhone.cpp : CMobilePhone 的实现

#include "stdafx.h"
#include "MobilePhone.h"
#include <iostream>

using namespace std;

// CMobilePhone

CMobilePhone::CMobilePhone()
{
	cout << "ding...欢迎使用山寨机COM组件！" << endl;
}

CMobilePhone::~CMobilePhone()
{
	cout << "感谢使用山寨机COM组件！dang..." << endl;
}

STDMETHODIMP CMobilePhone::talk(void)
{
	cout << "blablabla~~~~" << endl;
	cout << "@#$%^&*()!~~~~" << endl;
	cout << "blablabla~~~~" << endl;

	return S_OK;
}


STDMETHODIMP CMobilePhone::getName(BSTR* name)
{
	*name = _T("山寨机B920");
	return S_OK;
}
