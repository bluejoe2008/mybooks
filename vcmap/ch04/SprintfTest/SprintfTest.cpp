#include "stdafx.h"

void dec2hex(char * dec, char * hex, bool uppercase = false)
{
	int i;
	sscanf(dec, "%d", &i);
	if(uppercase)
	{
		sprintf(hex, "%X", i);
	}
	else
	{
		sprintf(hex, "%x", i);
	}
}

int main()
{
	char hex[20] = {0};
	dec2hex("100", hex);
	printf("0x%s\r\n", hex);
	dec2hex("255", hex);
	printf("0x%s\r\n", hex);
	dec2hex("255", hex, true);
	printf("0x%s\r\n", hex);

	return 0;
}
