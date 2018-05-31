#include "stdafx.h"

#define STRING_LENGTH 20

//写入字符串
void WriteString(CFile & file, char s[])
{
	file.Write(s, STRING_LENGTH);
}

//读取字符串
bool ReadString(CFile & file, char s[])
{
	return file.Read(s, STRING_LENGTH) == STRING_LENGTH;
}

//读取指定索引的字符串
bool ReadString(CFile & file, char s[], int index)
{
	//定位文件指针
	file.Seek(index * STRING_LENGTH, CFile::begin);
	return file.Read(s, STRING_LENGTH) == STRING_LENGTH;
}

int main()
{
	CFile file;
	file.Open("test.out", CFile::modeWrite | CFile::modeCreate);
	
	char s1[STRING_LENGTH] = "bluejoe";
	char s2[STRING_LENGTH] = "jerry";
	char s3[STRING_LENGTH] = "even";

	//写入3个定长字符串
	WriteString(file, s1);
	WriteString(file, s2);
	WriteString(file, s3);

	file.Close();
	//读取
	file.Open("test.out", CFile::modeRead);
	printf("文件大小: %d\r\n", file.GetLength());

	int i = 0;
	while(true)
	{
		char s[STRING_LENGTH];
		if(!ReadString(file, s))
			break;

		printf("[%d]: %s\r\n", i, s);
		i++;
	}

	char s[STRING_LENGTH];
	//读取第1条记录
	if(ReadString(file, s, 1))
		printf("[%d]: %s\r\n", 1, s);

	return 0;
}

