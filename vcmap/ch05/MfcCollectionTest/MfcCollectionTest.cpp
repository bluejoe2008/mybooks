#include "stdafx.h"

int main()
{
	CFile file;
	CFile::Remove(_T(""));
	CString s("");

	CArray<CString *> as;
	as.Add(&s);

	CTypedPtrArray<CObArray, CFile* > myArray;
	myArray.Add(&file);

	CPtrArray oa;
	oa.Add(&file);
	oa.Add(&s);

	return 0;
}