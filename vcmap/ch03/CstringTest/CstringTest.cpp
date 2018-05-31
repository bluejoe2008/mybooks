#include "stdafx.h"
#include <cstdio>
#include <cstring> 

int main ()
{
	char src[] = "Returns a pointer to the first occurrence in str1 of any of the characters that are part of str2, or a null pointer if there are no matches.";
	char key[] = "aeiou";
	char * cp;
	printf ("%s\r\n", src);
	printf ("元音字母: ");
	cp = strpbrk (src, key);
	int i = 0;
	while (cp != NULL)
	{
		i++;
		printf ("%c " , *cp);
		cp = strpbrk (cp + 1, key);
	}

	printf ("\r\n共有%d个元音\r\n", i);
	return 0;
}