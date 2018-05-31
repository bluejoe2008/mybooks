#include "stdafx.h"

class CMyObject : public CObject
{
	DECLARE_DYNCREATE(CMyObject)
};

IMPLEMENT_DYNCREATE(CMyObject, CObject)

int main()
{
	CMyObject o;
	CRuntimeClass * class1 = o.GetRuntimeClass();
	CRuntimeClass * class2 = RUNTIME_CLASS(CMyObject);
	
	ASSERT(class1 == class2);
	ASSERT(class1->IsDerivedFrom(RUNTIME_CLASS(CObject)));

	printf("%s\r\n", class1->m_lpszClassName);
	printf("%d\r\n", class1->m_nObjectSize);

	CMyObject * op = (CMyObject *)class1->CreateObject();
	ASSERT(class1 == op->GetRuntimeClass());
	delete op;

	return 0;
}
