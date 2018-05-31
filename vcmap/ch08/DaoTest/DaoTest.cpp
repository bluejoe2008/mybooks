#include "stdafx.h"
#include <afx.h>
#include <afxdao.h>

int main()
{
	try
	{
		CDaoDatabase db;
		//打开数据库
		db.Open(_T("..\\..\\hotel.mdb"));
		
		CDaoRecordset rs(&db);
		//打开记录集
		rs.Open(AFX_DAO_USE_DEFAULT_TYPE, _T("select ID,NAME,AGE,GENDER,WORDS from PERSON"), dbForwardOnly);

		//依次读取每一行
		while(!rs.IsEOF())
		{
			//使用COleVariant读取数据
			COleVariant var;
			CStringA name, gender, words;
			int id = 0, age = 0;

			//文本CStringA
			rs.GetFieldValue(1, var);
			name = (BSTR)var.pbstrVal;
			rs.GetFieldValue(3, var);
			gender = (BSTR)var.pbstrVal;
			rs.GetFieldValue(4, var);
			words = (BSTR)var.pbstrVal;

			//数值
			rs.GetFieldValue((short)0, var);
			id = var.intVal;
			rs.GetFieldValue(2, var);
			age = var.intVal;

			//输出
			printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
			rs.MoveNext();
		}

		//输出所有的表及其字段
		for(int i = 0; i < db.GetTableDefCount(); i++)
		{
			CDaoTableDefInfo tableInfo;
			db.GetTableDefInfo(i, tableInfo);

			//输出表名
			printf("%ls\r\n", tableInfo.m_strName);
			CDaoTableDef table(&db);
			table.Open(tableInfo.m_strName);

			//输出字段名
			for(int j = 0; j < table.GetFieldCount(); j++)
			{
				CDaoFieldInfo fieldInfo;
				table.GetFieldInfo(j, fieldInfo);

				printf("\t%ls\r\n", fieldInfo.m_strName);
			}
		}
	}
	catch(CException * e)
	{
		e->ReportError();
		e->Delete();
	}

	AfxDaoTerm();
	return 0;
}