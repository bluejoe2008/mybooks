#include "stdafx.h"
#include "mfc-person.h"
#include "ArchiveTest.h"

int main()
{
	setlocale(LC_ALL, "chs");

	//创建两个待写入的对象
	CPerson tong(_T("佟湘玉"), 28, false);
	tong.setWords(_T("额滴神啊..."));

	CPerson bai(_T("白展堂"), 27, true);
	bai.setWords(_T("葵花点穴手！"));

	//准备写入
	CFile oFile(_T("persons.archive"), CFile::modeCreate | CFile::modeWrite);
	CArchive oar(&oFile, CArchive::store);

	//序列化进去了
	oar << &tong << &bai;
	//oar.WriteObject(&tong);
	//oar.WriteObject(&bai);

	oar.Close();
	oFile.Close();

	//准备读取
	CFile iFile(_T("persons.archive"), CFile::modeRead);
	CArchive iar(&iFile, CArchive::load);

	//序列化出来了
	CPerson *p1, * p2;

	iar >> p1 >> p2;
	//p1 = iar.ReadObject(RUNTIME_CLASS(CPerson));
	//p2 = iar.ReadObject(RUNTIME_CLASS(CPerson));

	//看看他们是不是活的*_*ii
	p1->say();
	p2->say();

	delete p1;
	delete p2;
}
