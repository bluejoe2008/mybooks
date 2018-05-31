#include "stdafx.h"
#include "AdoTest.h"
#include <afx.h>
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")

int main()
{
	CoInitialize(NULL);

	try
	{
		//连接
		_ConnectionPtr pConn("ADODB.Connection");
		//记录集
		_RecordsetPtr pRs("ADODB.Recordset");

		//打开数据库
		pConn->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\\study\\keys\\hotel.mdb",  "", "", adConnectUnspecified);

		//打开记录集
		pRs->Open("select * from PERSON", _variant_t((IDispatch *)pConn,true), adOpenForwardOnly, adLockReadOnly, adCmdUnknown);

		//依次读取每一行
		while(!pRs->adoEOF)
		{
			//使用_variant_t读取数据
			CStringA name, gender, words;
			int id = 0, age = 0;
			_variant_t var;
			
			var = pRs->GetCollect(_variant_t("ID"));
			var.ChangeType(VT_I2);
			id = var.iVal;

			var = pRs->GetCollect(_variant_t("NAME"));
			var.ChangeType(VT_BSTR);
			name = var.bstrVal;

			var = pRs->GetCollect(_variant_t("AGE"));
			var.ChangeType(VT_I2);
			age = var.iVal;

			var = pRs->GetCollect(_variant_t("GENDER"));
			var.ChangeType(VT_BSTR);
			gender = var.bstrVal;

			var = pRs->GetCollect(_variant_t("WORDS"));
			var.ChangeType(VT_BSTR);
			words = var.bstrVal;

			//输出
			printf("%d\t%s\t%d\t%s\t%s\r\n", id, name, age, gender, words);
			pRs->MoveNext();
		}
	}
	catch(CException * e)
	{
		e->ReportError();
		e->Delete();
	}

	CoUninitialize();
	return 0;
}