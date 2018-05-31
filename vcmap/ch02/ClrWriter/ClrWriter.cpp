#include "stdafx.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
	String^ path = "test.out";

	//写文件
	StreamWriter^ sw = File::CreateText(path);
	sw->WriteLine("茴香豆的茴");
	sw->Close();

	//读文件
	StreamReader^ sr = File::OpenText(path);
	String^ s = "";
	if (s = sr->ReadLine())
	{
		Console::WriteLine(s);
	}
}