#include "stdafx.h"

//写入字符串
void WriteString(CFile & file, CString & s)
{
	int len = s.GetLength();
	//写入字符串的长度
	file.Write(&len, sizeof(int));
	//写入字符串
	file.Write((LPCTSTR)s, len);
}

//读取字符串
bool ReadString(CFile & file, CString & s)
{
	//先读取字符串长度
	int len;
	if(file.Read(&len, sizeof(int)) == sizeof(int))
	{
		TRACE("字符串长度: %d bytes\r\n", len);
	
		char * sp = new char[len + 1];
		sp[len] = 0;
		if(file.Read(sp, len) == len)
		{
			s = sp;
			delete [] sp;
			return true;
		}
		delete [] sp;
	}

	return false;
}

//读取指定索引的字符串
bool ReadString(CFile & file, CString & s, int index)
{
	//比较麻烦，必须从头开始数
	file.SeekToBegin();
	int i = 0;
	while(i < index)
	{
		//读取记录长度
		int len;
		if(file.Read(&len, sizeof(int)) != sizeof(int))
			return false;

		//定位文件指针
		file.Seek(len, CFile::current);
		i++;
	}

	return ReadString(file, s);
}

int main()
{
	CFile file;
	file.Open("test.out", CFile::modeWrite | CFile::modeCreate);
	
	CString s1 = "bluejoe";
	CString s2 = "jerry";
	CString s3 = "even";

	//写入
	WriteString(file, s1);
	WriteString(file, s2);
	WriteString(file, s3);

	file.Close();
	//读取
	file.Open("test.out", CFile::modeRead);
	printf("文件大小: %d bytes\r\n", file.GetLength());

	int i = 0;
	while(true)
	{
		CString s;
		if(!ReadString(file, s))
			break;

		printf("[%d]: %s\r\n", i, s);
		i++;
	}

	CString s;
	if(ReadString(file, s, 1))
		printf("[%d]: %s\r\n", 1, s);

	return 0;
}

