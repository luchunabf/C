#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设p 的值为0x00000000.
int main()
{
	printf("%p\n", p + 0x1);//0x00000014      结构体的大小是20个字节
	printf("%p\n", (unsigned long)p + 0x1);//0x00000001     非指针+1，不用管类型，就+1
	printf("%p\n", (unsigned int*)p + 0x1);//0x00000004     指针+1，类型为无符号整型，故+4
	system("pause");
	return 0;
}