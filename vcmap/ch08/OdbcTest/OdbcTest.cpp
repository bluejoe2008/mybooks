#include "stdafx.h"

#include <afx.h>
#include <odbcinst.h>
#include <sqlext.h>
#pragma comment( lib, "odbc32.lib" )

int main()
{
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;

	SQLCHAR * OutConnStr = (SQLCHAR * )malloc(255);
	SQLSMALLINT * OutConnStrLen = (SQLSMALLINT *)malloc(255);

	//环境句柄
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0); 

	SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); 

	//连接数据源
	SQLConnect(hdbc, (SQLCHAR*) "hotel", SQL_NTS, (SQLCHAR*) NULL, 0, NULL, 0);

	SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt); 

	SQLExecDirect(hstmt, (SQLCHAR*) "select ID,NAME,AGE,GENDER,WORDS from PERSON", SQL_NTS);

	//依次读取每行
	while (SQLFetch(hstmt) != SQL_NO_DATA)
	{
		SQLCHAR		name[255] = {0}, gender[255] = {0}, words[255] = {0};
		SQLINTEGER	id, age;
		SQLINTEGER	cb;

		//读取每列
		SQLGetData(hstmt, 1, SQL_C_ULONG, &id, 0, &cb);
		SQLGetData(hstmt, 2, SQL_C_CHAR, name, 255, &cb);
		SQLGetData(hstmt, 3, SQL_C_ULONG, &age, 0, &cb);
		SQLGetData(hstmt, 4, SQL_C_CHAR, gender, 255, &cb);
		SQLGetData(hstmt, 5, SQL_C_CHAR, words, 255, &cb);

		//输出
		printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
	}

	//释放资源
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	SQLDisconnect(hdbc);
	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	SQLFreeHandle(SQL_HANDLE_ENV, henv);

	return 0;
}

