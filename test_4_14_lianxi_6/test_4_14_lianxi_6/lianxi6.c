#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		Sleep(500);
		printf("%u\n", i);
	}
	system("pause");
	return 0;
}