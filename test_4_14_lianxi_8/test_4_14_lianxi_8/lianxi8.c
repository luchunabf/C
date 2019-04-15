#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	unsigned char i = 0;
	for (i = 0; i <= 255; i++)
	{
		Sleep(500);
		printf("hello world\n");
	}
	system("pause");
	return 0;
}