#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string src ("Returns a pointer to the first occurrence in str1 of any of the characters that are part of str2, or a null pointer if there are no matches.");
	cout << src << endl;
	cout << "元音字母: ";
	size_t cp;

	cp = src.find_first_of("aeiou");
	int i = 0;

	while (cp != string::npos)
	{
		cout << src.at(cp) << " ";
		cp = src.find_first_of("aeiou", cp + 1);
		i++;
	}

	cout << endl << "共有" << i << "个元音" << endl;
	return 0;
}
