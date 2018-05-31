#include "stdafx.h"

#include <afx.h>
#include <afxdb.h>

int main()
{
	try
	{
		CDatabase db;

		//打开数据库
		db.Open(_T("hotel"));
		
		CRecordset rs(&db);
		//打开记录集
		rs.Open(CRecordset::forwardOnly, _T("select ID,NAME,AGE,GENDER,WORDS from PERSON"));

		//输出所有列的信息
		for(int i = 0; i < rs.GetODBCFieldCount(); i++)
		{
			CODBCFieldInfo fieldInfo;
			rs.GetODBCFieldInfo(i, fieldInfo);
			printf("%s\t%d\r\n", fieldInfo.m_strName, fieldInfo.m_nSQLType);
		}

		//依次读取每一行
		while(!rs.IsEOF())
		{
			CString name, gender, words;
			int id = 0, age = 0;

			//文本类型的读取比较简单
			rs.GetFieldValue(1, name);
			rs.GetFieldValue(3, gender);
			rs.GetFieldValue(4, words);

			//其它类型的读取稍微复杂些
			CDBVariant var;
			rs.GetFieldValue((short)0, var);
			id = var.m_iVal;
			rs.GetFieldValue(2, var);
			age = var.m_iVal;

			//输出
			printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
			rs.MoveNext();
		}
	}
	catch(CDBException * e)
	{
		printf(e->m_strError);
		e->Delete();
	}

	return 0;
}

