#include "stdafx.h"
#include <afx.h>
#include <atldbcli.h>
#include <atldbsch.h>

class CPersonAccessor
{
public:
	int m_ID;
	char m_NAME[51];
	int m_AGE;
	char m_GENDER[2];
	char m_WORDS[8000];
};

int main()
{
	CoInitialize(NULL);

	CDataSource ds;
	ds.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Data Source=hotel;");
	CSession sn;
	sn.Open(ds);

	//输出所有表
	CTables tables;
	tables.Open(sn);
	while(tables.MoveNext() == S_OK)
	{
		//输出表名
		printf("%ls:%ls\r\n", tables.m_szType, tables.m_szName);

		//输出字段
		CColumns columns;
		columns.Open(sn, NULL, NULL, tables.m_szName);
		while(columns.MoveNext() == S_OK)
		{
			printf("\t%d:%ls\r\n", columns.m_nDataType, columns.m_szColumnName);
		}
	}

	//输出PERSON表的所有记录
	CCommand<CManualAccessor> cmd;

	CPersonAccessor accessor;
	int nFields = 5;

	//绑定之
	cmd.CreateAccessor(nFields, &accessor, sizeof(accessor));

	//绑定每个字段
	cmd.AddBindEntry(1, DBTYPE_I4, sizeof(accessor.m_ID), &accessor.m_ID);
	cmd.AddBindEntry(2, DBTYPE_STR, sizeof(accessor.m_NAME), accessor.m_NAME);
	cmd.AddBindEntry(3, DBTYPE_I4, sizeof(accessor.m_AGE), &accessor.m_AGE);
	cmd.AddBindEntry(4, DBTYPE_STR, sizeof(accessor.m_GENDER), accessor.m_GENDER);
	cmd.AddBindEntry(5, DBTYPE_STR, sizeof(accessor.m_WORDS), accessor.m_WORDS);

	cmd.Open(sn, _T("select ID,NAME,AGE,GENDER,WORDS from PERSON"));
	//输出数据
	while(cmd.MoveNext() == S_OK)
	{
		//输出
		printf("%d\t%s\t%d\t%s\t%s\r\n", accessor.m_ID, accessor.m_NAME, accessor.m_AGE, accessor.m_GENDER, accessor.m_WORDS);
	}

	CoUninitialize();
	return 0;
}