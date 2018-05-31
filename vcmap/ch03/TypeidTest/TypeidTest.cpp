#include "stdafx.h"
#include <windows.h>
#include <atlstr.h>
#include <typeinfo>

using namespace std;

int main()                              
{                                       
	char msg[] = "hello, world!";
	LPSTR lp = msg;
	CString s = msg;

	printf("%s\r\n", typeid(msg).name());
	printf("%s\r\n", typeid(lp).name());
	printf("%s\r\n", typeid(s).name());

	return 0;
}
