#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";//栈上面的两部分
	char* str3 = "hello world";
	char* str4 = "hello world";//指针，指向常量区的同一个地址
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	system("pause");
	return 0;
}