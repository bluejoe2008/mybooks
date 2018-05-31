#include "stdafx.h"
#include "comutil.h"
#include <clocale>

#import "msxml4.dll"

void WritePerson(MSXML2::IXMLDOMDocument2Ptr pDocument, MSXML2::IXMLDOMNodePtr pParentNode, CString name, long age)
{
	//创建一个<person>节点
	MSXML2::IXMLDOMElementPtr pPersonNode = pDocument->createElement(_T("person"));
	pParentNode->appendChild(pPersonNode);

	//写入name
	MSXML2::IXMLDOMElementPtr pPersonNameNode = pDocument->createElement(_T("name"));
	pPersonNameNode->text = _bstr_t(name);

	//写入age
	MSXML2::IXMLDOMElementPtr pPersonAgeNode = pDocument->createElement(_T("age"));
	pPersonAgeNode->text = _bstr_t(age);

	pPersonNode->appendChild(pPersonNameNode);
	pPersonNode->appendChild(pPersonAgeNode);
}

void WritePersons()
{
	MSXML2::IXMLDOMDocument2Ptr pXMLDocument;
	pXMLDocument.CreateInstance(__uuidof(MSXML2::DOMDocument));
	MSXML2::IXMLDOMElementPtr pPersonsNode = pXMLDocument->createElement(_T("persons"));
	pXMLDocument->appendChild(pPersonsNode);

	WritePerson(pXMLDocument, pPersonsNode, _T("佟湘玉"), 28);
	WritePerson(pXMLDocument, pPersonsNode, _T("白展堂"), 27);

	pXMLDocument->save(_T("persons.xml"));
}

void ReadPersons()
{
	MSXML2::IXMLDOMDocument2Ptr pXMLDocument;
	pXMLDocument.CreateInstance(__uuidof(MSXML2::DOMDocument));

	pXMLDocument->load(_T("persons.xml"));

	MSXML2::IXMLDOMElementPtr pRootNode = pXMLDocument->documentElement;
	//查找<person>节点
	MSXML2::IXMLDOMNodeListPtr pPersonNodes = pRootNode->selectNodes(_T("person"));

	CString s;
	long size = pPersonNodes->length;

	for(int i = 0; i < size; i++)
	{
		MSXML2::IXMLDOMNodePtr pPersonNode = pPersonNodes->item[i];

		MSXML2::IXMLDOMNodePtr pNameNode = pPersonNode->selectSingleNode(_T("name"));
		MSXML2::IXMLDOMNodePtr pAgeNode = pPersonNode->selectSingleNode(_T("age"));

		s.Format(_T("%sname: %s\tage: %s\r\n"), s, (LPCTSTR)pNameNode->text, (LPCTSTR)pAgeNode->text);
	}

	_tprintf(s);
}

int _tmain()
{
	setlocale(LC_ALL, "chs");

	HRESULT hr;
	hr = ::CoInitialize(NULL); 

	WritePersons();
	ReadPersons();

	::CoUninitialize();
	return 0;
}