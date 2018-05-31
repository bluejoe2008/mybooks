#include "stdafx.h"
#include <atltime.h>

int main()
{
	int year, month, day;
	printf("输入您的出生日期(年 月 日)：");
	scanf("%d%d%d", &year, &month, &day);

	CTime birthday(year, month, day, 0, 0, 0);
	CTime now = CTime::GetCurrentTime();

	CTimeSpan span = now - birthday;
	printf("您已生活%d小时！\r\n", span.GetTotalHours());

	return 0;
}
