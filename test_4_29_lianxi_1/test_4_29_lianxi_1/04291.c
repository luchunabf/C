#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	const char a[] = "abcdef";
	const char b[] = "bbb";
	if (strlen(a) > strlen(b))
	{
		printf("a>b\n");
	}
	else
	{
		printf("a<=b\n");
	}
	system("pause");
	return 0;
}