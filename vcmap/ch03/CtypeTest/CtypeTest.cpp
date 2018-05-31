#include "stdafx.h"
#include <cstdio>
#include <cctype>

int main()
{
	char src[] = "Hello World!";
	char * cp = src;
	while(*cp)
	{
		//小写字母转成大写
		if(islower(*cp))
			printf("%c", toupper(*cp));
		else 
		{
			//大写字母转成小写
			if(isupper(*cp))
				printf("%c", tolower(*cp));
			//其它字符
			else
				printf("@");
		}

		cp++;
	}

	return 0;
}