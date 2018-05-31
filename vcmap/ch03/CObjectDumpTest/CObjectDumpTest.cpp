#include "stdafx.h"

class CPerson : public CObject
{
	DECLARE_DYNAMIC(CPerson)
private:
	CString _name;
public:
	CPerson(CString name)
		: _name(name)
	{
	}
	
	virtual void Dump(CDumpContext& dc) const
	{
		CObject::Dump(dc);
		dc << (LPCTSTR)_name;
	}
};

IMPLEMENT_DYNAMIC(CPerson, CObject)

int _tmain()
{

#if _DEBUG
	afxDump.SetDepth(1);
#endif

	CWnd *pWnd = new CWnd();
	CPerson *pPerson = new CPerson(_T("bluejoe"));
	return 0;
}