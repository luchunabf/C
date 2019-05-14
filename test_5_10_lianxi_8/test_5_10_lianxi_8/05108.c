#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	union Un
	{
		char c;
		int i;
	};
	union Un un;
	printf("%d\n", sizeof(un));
	printf("%d\n", &(un.c));
	printf("%d\n", &(un.i));
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
	system("pause");
	return 0;
}