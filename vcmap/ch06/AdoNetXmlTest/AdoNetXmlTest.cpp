#include "stdafx.h"

#using <mscorlib.dll>
#using <system.dll>
#using <system.data.dll>

using namespace System;
using namespace System::Data;

//添加指定内容一条记录
void AddRow(DataTable ^ dt, String ^ name, int age, bool gender, String ^ words)
{
	//创建记录
	DataRow ^ dr = dt->NewRow();

	dr["NAME"] = name;
	dr["AGE"] = age;
	dr["GENDER"] = gender;
	dr["WORDS"] = words;

	//添加记录
	dt->Rows->Add(dr);
}

//创建一个数据集
DataSet ^ CreateDataSet()
{
	DataSet ^ ds = gcnew DataSet();

	//创建数据表
	DataTable ^ dt = gcnew DataTable();
	dt->TableName = "PERSONS";

	//添加列
	dt->Columns->Add("NAME", (gcnew String(""))->GetType());
	dt->Columns->Add("AGE", (gcnew Int32())->GetType());
	dt->Columns->Add("GENDER", (gcnew Boolean())->GetType());
	dt->Columns->Add("WORDS", (gcnew String(""))->GetType());

	//添加数据表
	ds->Tables->Add(dt);

	//添加数据行
	AddRow(dt, "佟湘玉", 28, false, "额滴神啊…");
	AddRow(dt, "白展堂", 27, true, "葵花点穴手！");
	AddRow(dt, "郭芙蓉", 22, false, "排山倒海，排山再倒海，排山再再再倒海…");
	AddRow(dt, "吕轻侯", 24, true, "子曾经曰过…");
	AddRow(dt, "李秀莲", 30, true, "都低调啊低调！！");
	AddRow(dt, "莫小贝", 12, false, "嫂子~~~~~");

	return ds;
}

void SaveDataSet()
{
	DataSet ^ ds = CreateDataSet();
	ds->WriteXml("dataset.xml");
	ds->WriteXmlSchema("dataset.xsd");
}

void LoadDataSet()
{
	DataSet ^ ds = gcnew DataSet();
	ds->ReadXmlSchema("dataset.xsd");
	ds->ReadXml("dataset.xml");

	//枚举所有表
	for(int i = 0; i < ds->Tables->Count; i++)
	{
		DataTable ^ table = ds->Tables[i];
		Console::WriteLine(table->TableName);

		//输出字段
		for(int j = 0; j < table->Columns->Count; j++)
		{
			DataColumn ^ column = table->Columns[j];
			Console::WriteLine("\t{0}\t{1}", column->Caption, column->DataType->FullName);
		}
	}

	//列出PERSON表的所有记录
	DataTable ^ persons = ds->Tables["PERSONS"];
	for(int i = 0; i < persons->Rows->Count; i++)
	{
		DataRow ^ row = persons->Rows[i];
		Console::WriteLine("{0}\t{1}\t{2}\t{3}", row["NAME"], row["AGE"], row["GENDER"], row["WORDS"]);
	}
}

int main(array<System::String ^> ^args)
{
	SaveDataSet();
	LoadDataSet();

	return 0;
}
