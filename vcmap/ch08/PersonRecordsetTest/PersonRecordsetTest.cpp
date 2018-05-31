#include "stdafx.h"

#include "PersonRecordsetTest.h"
#include "PERSON.h"

int main()
{
	setlocale(LC_ALL, "chs");

	try
	{
		CDatabase db;
		//打开数据库
		db.Open(_T("hotel"));
		
		CPersonRecordset rs(&db);
		//打开记录集
		rs.Open(CRecordset::forwardOnly, _T("select ID,NAME,AGE,GENDER,WORDS from PERSON"));

		//依次读取每一行
		while(!rs.IsEOF())
		{
			//输出
			CString line;
			line.Format(_T("%d\t%s\t%d\t%s\t%s\r\n"), rs.m_ID, rs.m_NAME, rs.m_AGE, rs.m_GENDER, rs.m_WORDS);
			rs.MoveNext();

			_tprintf(line);
		}
	}
	catch(CDBException * e)
	{
		_tprintf(e->m_strError);
		e->Delete();
	}

	return 0;
}