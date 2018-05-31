#include "stdafx.h"

int main()
{
	setlocale(LC_ALL, "chs");

	CTime now = CTime::GetCurrentTime();
	CString s = now.Format("%Y年%m月%d日 %H时%M分%S秒\r\n本地表示: %c\r\n");
	_tprintf(_T("%s"), s);

	return 0;
}
