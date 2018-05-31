// PersonCommand.h : CPersonCommand 的声明

#pragma once

// 代码生成在 2009年2月7日, 20:04

class CPersonCommandAccessor
{
public:
	LONG m_ID;
	TCHAR m_NAME[51];
	LONG m_AGE;
	TCHAR m_GENDER[2];
	// ISequentialStream* m_WORDS;
	TCHAR m_WORDS[8000];

	// 以下向导生成的数据成员包含
	//列映射中相应字段的状态值。
	// 可以使用这些值保存数据库返回的 NULL 值或在编译器返回
	// 错误时保存错误信息。有关如何使用
	//这些字段的详细信息，
	// 请参见 Visual C++ 文档中的
	//“向导生成的访问器中的字段状态数据成员”。
	// 注意: 在设置/插入数据前必须初始化这些字段!

	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwNAMEStatus;
	DBSTATUS m_dwAGEStatus;
	DBSTATUS m_dwGENDERStatus;
	DBSTATUS m_dwWORDSStatus;

	// 以下向导生成的数据成员包含
	//列映射中相应字段的长度值。
	// 注意: 对变长列，必须在设置/插入
	//       数据前初始化这些字段!

	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwNAMELength;
	DBLENGTH m_dwAGELength;
	DBLENGTH m_dwGENDERLength;
	DBLENGTH m_dwWORDSLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		// pPropSet->AddProperty(DBPROP_ISequentialStream, true);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
		hr = _db.OpenFromInitializationString(L"Provider=MSDASQL.1;Persist Security Info=False;Data Source=hotel;");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	DEFINE_COMMAND_EX(CPersonCommandAccessor, L" \
	SELECT \
		ID, \
		NAME, \
		AGE, \
		GENDER, \
		WORDS \
		FROM PERSON")

// 该表/命令包含可以通过 ISequentialStream 接口
// 访问的列。然而，并非所有提供程序都支持此功能，
// 即使那些确实支持此功能的提供程序通常也仅限为
// 每个行集只有一个 ISequentialStream。
// 如果希望在此访问器中使用流，请使用以下代码的
// 示例行，并将 DBPROP_ISequentialStream 行集属
// 性设置为 True。然后就可以使用 Read() 方法读
// 取数据或使用 Write()方法写入数据(注意此操作
// 要求将 STGM_READ 流属性更改为 STGM_WRITE 或 
// STGM_READWRITE)。有关 ISequentialStream 绑定
// 的详细信息，请参见文档

	// 为解决某些提供程序的若干问题，以下代码可能以
	// 不同于提供程序所报告的顺序来绑定列

	BEGIN_COLUMN_MAP(CPersonCommandAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_NAME, m_dwNAMELength, m_dwNAMEStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_AGE, m_dwAGELength, m_dwAGEStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_GENDER, m_dwGENDERLength, m_dwGENDERStatus)
		// BLOB_ENTRY_LENGTH_STATUS(5, IID_ISequentialStream, STGM_READ, m_WORDS, m_dwWORDSLength, m_dwWORDSStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_WORDS, m_dwWORDSLength, m_dwWORDSStatus)
	END_COLUMN_MAP()
};

class CPersonCommand : public CCommand<CAccessor<CPersonCommandAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, NULL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		ReleaseCommand();
		CloseDataSource();
	}
};


