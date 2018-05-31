#include "stdafx.h"
#include <cstdio>

int main()
{
	//写入文件
	FILE * fp = fopen("test.out", "w");
	fprintf(fp, "茴香豆的茴");
	fclose(fp);

	//读取文件
	fp = fopen("test.out", "r");
	char line[256];
	fscanf(fp, "%s", line);
	printf("%s\r\n", line);
	fclose(fp);

	return 0;
}