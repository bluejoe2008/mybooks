// PERSON.h : CPersonRecordset 的声明

#pragma once

// 代码生成在 2008年10月5日, 10:39

class CPersonRecordset : public CRecordset
{
public:
	CPersonRecordset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPersonRecordset)

	long	m_ID;
	CStringW	m_NAME;
	long	m_AGE;
	CStringW	m_GENDER;
	CStringW	m_WORDS;

// 重写
	// 向导生成的虚函数重写
	public:
	virtual CString GetDefaultConnect();	// 默认连接字符串

	virtual CString GetDefaultSQL(); 	// 记录集的默认 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 支持

// 实现
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


