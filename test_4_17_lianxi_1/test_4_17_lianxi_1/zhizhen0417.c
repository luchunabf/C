#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//4*4
	printf("%d\n", sizeof(a+0));//4(整形一个字节？？四个字节？？)
	printf("%d\n", sizeof(*a));// 4                    4或8
	printf("%d\n", sizeof(a+1));//4(整形一个字节？？四个字节？？)
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4或8
	printf("%d\n", sizeof(*&a));//16
	printf("%d\n", sizeof(&a+1));//4或8
	printf("%d\n", sizeof(&a[0]));//4或8
	printf("%d\n", sizeof(&a[0]+1));//4或8


	system("pause");
	return 0;
}