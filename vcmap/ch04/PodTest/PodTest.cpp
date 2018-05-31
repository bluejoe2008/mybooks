#include "stdafx.h"
#include <cstring>

//PERSON为POD
struct PERSON
{
	char _name[16];
	int _age;
	bool _gender;
};

void print(PERSON * p)
{
	printf("%s,%d,%s\r\n", p->_name, p->_age, (p->_gender ? "男" : "女"));
}

int main()                              
{
	//POD对象可以使用初始化列表
	PERSON p1 = {"佟湘玉", 28, false};
	PERSON p3 = {"白展堂", 26, true};
	print(&p1);
	print(&p3);

	//将p1转储为char数组
	char bytes[sizeof(PERSON)];
	memcpy(bytes, &p1, sizeof(PERSON));

	PERSON p2;
	memset(&p2, 0, sizeof(PERSON));
	print(&p2);

	//将char数组还原为p2
	memcpy(&p2, bytes, sizeof(PERSON));
	print(&p2);

	//将p3拷贝至p2
	memcpy(&p2, &p3, sizeof(PERSON));
	print(&p2);

	return 0;
}
