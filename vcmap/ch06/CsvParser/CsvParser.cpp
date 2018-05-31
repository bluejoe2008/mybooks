#include "stdafx.h"
#include "sheet.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	CSheet sheet;

	//打开csv文件
	ifstream in("test.csv");
	//加载至CSheet
	sheet.loadFrom(in);

	for(int i = 0; i < sheet.getRowCount(); i++)
	{
		_tprintf(_T("[%02d] "), i);
		//获取指定行
		CRow row = sheet.getRow(i);
		for(int j = 0; j < row.getColumnCount(); j++)
		{
			//获取指定列
			CString s = row.getColumn(j);
			_tprintf(_T("%s/"), s);
		}
		_tprintf(_T("\r\n"), i);
	}

	return 0;
}