// PERSON.h : CPersonRecordset 类的实现
#include "stdafx.h"
#include "PERSON.h"



// CPersonRecordset 实现

// 代码生成在 2008年10月5日, 10:39

IMPLEMENT_DYNAMIC(CPersonRecordset, CRecordset)

CPersonRecordset::CPersonRecordset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_NAME = L"";
	m_AGE = 0;
	m_GENDER = L"";
	m_WORDS = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

CString CPersonRecordset::GetDefaultConnect()
{
	return _T("DSN=hotel;DBQ=E:\\study\\keys\\hotel.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CPersonRecordset::GetDefaultSQL()
{
	return _T("[PERSON]");
}

void CPersonRecordset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Long(pFX, _T("[AGE]"), m_AGE);
	RFX_Text(pFX, _T("[GENDER]"), m_GENDER);
	RFX_Text(pFX, _T("[WORDS]"), m_WORDS);

}
/////////////////////////////////////////////////////////////////////////////
// CPersonRecordset 诊断

#ifdef _DEBUG
void CPersonRecordset::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPersonRecordset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


