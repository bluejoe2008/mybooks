#include "StdAfx.h"
#include "Row.h"

CRow::CRow(CStringArray * row)
{
	_row = row;
}

int CRow::getColumnCount(void)
{
	return _row->GetCount();
}

CString CRow::getColumn(int i)
{
	return _row->GetAt(i);
}
