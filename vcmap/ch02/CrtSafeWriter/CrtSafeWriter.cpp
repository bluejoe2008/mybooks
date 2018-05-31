#include "stdafx.h"
#include <cstdio>

int main()
{
	//写入文件
	FILE * fp;
	fopen_s(&fp, "test.out", "w");
	fprintf_s(fp, "茴香豆的茴");
	fclose(fp);

	//读取文件
	fopen_s(&fp, "test.out", "r");
	char line[256];
	fscanf_s(fp, "%s", line, 256);
	printf_s("%s\r\n", line);
	fclose(fp);

	return 0;
}