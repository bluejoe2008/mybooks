#include "stdafx.h"

#using <mscorlib.dll>
#using <system.dll>
#using <system.data.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::Common;
using namespace System::Data::OleDb;
using namespace System::ComponentModel;

int main(array<System::String ^> ^args)
{
	//获取连接
	IDbConnection ^ conn = gcnew OleDbConnection ("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\\study\\keys\\ch08\\hotel.mdb");
	//创建命令
	IDbCommand ^ comm = conn->CreateCommand();
	comm->CommandText = "select ID,NAME,AGE,GENDER,WORDS from PERSON";

	conn->Open();
	//创建数据阅读器
	IDataReader ^ reader = comm->ExecuteReader();

	//遍历输出
	while(reader->Read())
	{
		Console::Write(reader->GetInt32(0));
		Console::Write("\t");
		Console::Write(reader->GetString(1));
		Console::Write("\t");
		Console::Write(reader->GetInt32(2));
		Console::Write("\t");
		Console::Write(reader->GetString(3));
		Console::Write("\t");
		Console::WriteLine(reader->GetString(4));
	}

	return 0;
}
